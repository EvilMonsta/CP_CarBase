#ifndef IDS_CONTAINER_H
#define IDS_CONTAINER_H
#include <map>
#include <vector>
#include<iostream>
#include<fstream>
#include<QDebug>
#include<open_file_exception.h>
using namespace std;

template <typename VehicleType>
class IdsContainer {
public:

    void addVehicleId(int keyId, int vehicleId) {
        registry[keyId].push_back(vehicleId);
        qDebug() << "successful";
        qDebug() << keyId;
    }
    // void addVehicleId(int keyId, int newElementId) {
    //     auto it = registry.find(keyId);
    //     vector<int>& ids = it->second;
    //     // registry[keyId].push_back(newElementId);
    //     if(find(ids.begin(),ids.end(),newElementId) == ids.end())
    //         ids.push_back(newElementId);
    //     qDebug() << "successful";
    //     qDebug() << keyId;
    // }

    const vector<int> getOneTypeVehicleIds(int id) const {
        vector<int> ids;

        auto it = registry.find(id);
        if (it != registry.end()) {

            ids = it->second;
        }

        return ids;
    }

    vector<int> getAllVehicleIds() const {
        vector<int> allIds;
        for (const auto& [_, ids] : registry) {
            allIds.insert(allIds.end(), ids.begin(), ids.end());
        }
        return allIds;
    }

    bool saveToFile(const string& filename) const {
        try {
            ofstream file(filename);
            if (!file.is_open()) {
                throw OpenFileException("Невозможно открыть файл для сохранения: " + filename);
            }

            for (const auto& [keyId, ids] : registry) {
                file << keyId << ":";
                for (size_t i = 0; i < ids.size(); ++i) {
                    file << ids[i];
                    if (i < ids.size() - 1) file << ",";
                }
                file << "\n";
            }
            file.close();
            return true;
        } catch (const OpenFileException& ofexp) {
            OpenFileException::showErrorDialog(QString::fromStdString(ofexp.what()));
            return false;
        }
    }

    bool loadFromFile(const string& filename) {
        try {
            ifstream file(filename);
            if (!file.is_open()) {
                throw OpenFileException("Невозможно открыть файл для загрузки данных: " + filename);
            }

            registry.clear();

            string line;
            while (getline(file, line)) {
                size_t colonPos = line.find(':');
                if (colonPos == string::npos) continue;

                int keyId = stoi(line.substr(0, colonPos));
                vector<int> ids;
                string idsStr = line.substr(colonPos + 1);

                size_t pos = 0;
                while ((pos = idsStr.find(',')) != string::npos) {
                    ids.push_back(stoi(idsStr.substr(0, pos)));
                    idsStr.erase(0, pos + 1);
                }
                if (!idsStr.empty()) {
                    ids.push_back(stoi(idsStr));
                }

                registry[keyId] = ids;
            }

            file.close();
            return true;
        } catch (const OpenFileException& ofexp) {
            OpenFileException::showErrorDialog(QString::fromStdString(ofexp.what()));
            return false;
        }

    }

    class Iterator {
    public:
        Iterator(
            typename std::map<int, std::vector<int>>::iterator regIt,
            typename std::map<int, std::vector<int>>::iterator regEnd,
            typename std::vector<int>::iterator idIt)
            : regIt(regIt), regEnd(regEnd), idIt(idIt) {
            skipEmpty();
        }

        int operator*() const {
            return *idIt;
        }

        Iterator& operator++() {
            ++idIt;
            if (idIt == regIt->second.end()) {
                ++regIt;
                if (regIt != regEnd) {
                    idIt = regIt->second.begin();
                }
            }
            skipEmpty();
            return *this;
        }

        Iterator& operator--() {
            if (idIt == regIt->second.begin()) {
                do {
                    --regIt;
                } while (regIt != regEnd && regIt->second.empty());
                idIt = regIt->second.end();
            }
            --idIt;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return regIt != other.regIt || (regIt != regEnd && idIt != other.idIt);
        }

    private:
        typename std::map<int, std::vector<int>>::iterator regIt;
        typename std::map<int, std::vector<int>>::iterator regEnd;
        typename std::vector<int>::iterator idIt;

        void skipEmpty() {
            while (regIt != regEnd && idIt == regIt->second.end()) {
                ++regIt;
                if (regIt != regEnd) {
                    idIt = regIt->second.begin();
                }
            }
        }
    };

    // Константный итератор
    class ConstIterator {
    public:
        ConstIterator(
            typename std::map<int, std::vector<int>>::const_iterator regIt,
            typename std::map<int, std::vector<int>>::const_iterator regEnd,
            typename std::vector<int>::const_iterator idIt)
            : regIt(regIt), regEnd(regEnd), idIt(idIt) {
            skipEmpty();
        }

        int operator*() const {
            return *idIt;
        }

        ConstIterator& operator++() {
            ++idIt;
            if (idIt == regIt->second.end()) {
                ++regIt;
                if (regIt != regEnd) {
                    idIt = regIt->second.begin();
                }
            }
            skipEmpty();
            return *this;
        }

        ConstIterator& operator--() {
            if (idIt == regIt->second.begin()) {
                do {
                    --regIt;
                } while (regIt != regEnd && regIt->second.empty());
                idIt = regIt->second.end();
            }
            --idIt;
            return *this;
        }

        bool operator!=(const ConstIterator& other) const {
            return regIt != other.regIt || (regIt != regEnd && idIt != other.idIt);
        }

    private:
        typename std::map<int, std::vector<int>>::const_iterator regIt;
        typename std::map<int, std::vector<int>>::const_iterator regEnd;
        typename std::vector<int>::const_iterator idIt;

        void skipEmpty() {
            while (regIt != regEnd && idIt == regIt->second.end()) {
                ++regIt;
                if (regIt != regEnd) {
                    idIt = regIt->second.begin();
                }
            }
        }
    };

    // Обратный итератор
    class ReverseIterator {
    public:
        ReverseIterator(
            typename std::map<int, std::vector<int>>::reverse_iterator regIt,
            typename std::map<int, std::vector<int>>::reverse_iterator regEnd,
            typename std::vector<int>::reverse_iterator idIt)
            : regIt(regIt), regEnd(regEnd), idIt(idIt) {
            skipEmpty();
        }

        int operator*() const {
            return *idIt;
        }

        ReverseIterator& operator++() {
            ++idIt;
            if (idIt == regIt->second.rend()) {
                ++regIt;
                if (regIt != regEnd) {
                    idIt = regIt->second.rbegin();
                }
            }
            skipEmpty();
            return *this;
        }

        ReverseIterator& operator--() {
            if (idIt == regIt->second.rbegin()) {
                do {
                    ++regIt;
                } while (regIt != regEnd && regIt->second.empty());
                idIt = regIt->second.rend();
            }
            --idIt;
            return *this;
        }

        bool operator!=(const ReverseIterator& other) const {
            return regIt != other.regIt || (regIt != regEnd && idIt != other.idIt);
        }

    private:
        typename std::map<int, std::vector<int>>::reverse_iterator regIt;
        typename std::map<int, std::vector<int>>::reverse_iterator regEnd;
        typename std::vector<int>::reverse_iterator idIt;

        void skipEmpty() {
            while (regIt != regEnd && idIt == regIt->second.rend()) {
                ++regIt;
                if (regIt != regEnd) {
                    idIt = regIt->second.rbegin();
                }
            }
        }
    };

    // Обратный константный итератор
    class ConstReverseIterator {
    public:
        ConstReverseIterator(
            typename std::map<int, std::vector<int>>::const_reverse_iterator regIt,
            typename std::map<int, std::vector<int>>::const_reverse_iterator regEnd,
            typename std::vector<int>::const_reverse_iterator idIt)
            : regIt(regIt), regEnd(regEnd), idIt(idIt) {
            skipEmpty();
        }

        int operator*() const {
            return *idIt;
        }

        ConstReverseIterator& operator++() {
            ++idIt;
            if (idIt == regIt->second.rend()) {
                ++regIt;
                if (regIt != regEnd) {
                    idIt = regIt->second.rbegin();
                }
            }
            skipEmpty();
            return *this;
        }

        ConstReverseIterator& operator--() {
            if (idIt == regIt->second.rbegin()) {
                do {
                    ++regIt;
                } while (regIt != regEnd && regIt->second.empty());
                idIt = regIt->second.rend();
            }
            --idIt;
            return *this;
        }

        bool operator!=(const ConstReverseIterator& other) const {
            return regIt != other.regIt || (regIt != regEnd && idIt != other.idIt);
        }

    private:
        typename std::map<int, std::vector<int>>::const_reverse_iterator regIt;
        typename std::map<int, std::vector<int>>::const_reverse_iterator regEnd;
        typename std::vector<int>::const_reverse_iterator idIt;

        void skipEmpty() {
            while (regIt != regEnd && idIt == regIt->second.rend()) {
                ++regIt;
                if (regIt != regEnd) {
                    idIt = regIt->second.rbegin();
                }
            }
        }
    };

    Iterator begin() {
        return Iterator(
            registry.begin(),
            registry.end(),
            registry.empty() ? typename std::vector<int>::iterator() : registry.begin()->second.begin());
    }

    Iterator end() {
        return Iterator(
            registry.end(),
            registry.end(),
            typename std::vector<int>::iterator());
    }

    ConstIterator cbegin() const {
        return ConstIterator(
            registry.cbegin(),
            registry.cend(),
            registry.empty() ? typename std::vector<int>::const_iterator() : registry.cbegin()->second.cbegin());
    }

    ConstIterator cend() const {
        return ConstIterator(
            registry.cend(),
            registry.cend(),
            typename std::vector<int>::const_iterator());
    }

    ReverseIterator rbegin() {
        return ReverseIterator(
            registry.rbegin(),
            registry.rend(),
            registry.empty() ? typename std::vector<int>::reverse_iterator() : registry.rbegin()->second.rbegin());
    }

    ReverseIterator rend() {
        return ReverseIterator(
            registry.rend(),
            registry.rend(),
            typename std::vector<int>::reverse_iterator());
    }

    ConstReverseIterator crbegin() const {
        return ConstReverseIterator(
            registry.rbegin(),
            registry.rend(),
            registry.empty() ? typename std::vector<int>::const_reverse_iterator() : registry.rbegin()->second.crbegin());
    }

    ConstReverseIterator crend() const {
        return ConstReverseIterator(
            registry.rend(),
            registry.rend(),
            typename std::vector<int>::const_reverse_iterator());
    }
private:
    map<int, vector<int>> registry;
};

#endif //IDS_CONTAINER_H
