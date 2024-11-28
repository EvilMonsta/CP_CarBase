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

    vector<int> getKeys()  {
        vector<int> keys;
        for(const auto& key: registry) {
            keys.push_back(key.first);
        }
        return keys;
    }

    void changeIds(vector<int> ids, int keyId){
        registry[keyId] = ids;
    }
    void addVehicleId(int keyId, int vehicleId) {
        registry[keyId].push_back(vehicleId);
        qDebug() << "successful";
        qDebug() << keyId;
    }

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
        explicit Iterator(typename map<int, vector<int>>::iterator it)
            : current(it) {}

        int operator*() const  { return current->first; }
        const int* operator->() const { return &(current->first); }

        Iterator& operator++() {
            ++current;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        Iterator& operator--() {
            --current;
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

    private:
        typename map<int, vector<int>>::iterator current;
    };

    class ConstIterator {
    public:
        explicit ConstIterator(typename map<int, vector<int>>::const_iterator it)
            : current(it) {}

        const int& operator*() const { return current->first; }
        const int* operator->() const { return &(current->first); }

        ConstIterator& operator++() {
            ++current;
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator temp = *this;
            ++(*this);
            return temp;
        }

        ConstIterator& operator--() {
            --current;
            return *this;
        }

        ConstIterator operator--(int) {
            ConstIterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const ConstIterator& other) const {
            return current == other.current;
        }

        bool operator!=(const ConstIterator& other) const {
            return current != other.current;
        }

    private:
        typename map<int, vector<int>>::const_iterator current;
    };

    class ReverseIterator {
    public:
        explicit ReverseIterator(typename map<int, vector<int>>::reverse_iterator it)
            : current(it) {}

        int operator*() const{ return current->first; }
        const int* operator->() const { return &(current->first); }

        ReverseIterator& operator++() {
            ++current;
            return *this;
        }

        ReverseIterator operator++(int) {
            ReverseIterator temp = *this;
            ++(*this);
            return temp;
        }

        ReverseIterator& operator--() {
            --current;
            return *this;
        }

        ReverseIterator operator--(int) {
            ReverseIterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const ReverseIterator& other) const {
            return current == other.current;
        }

        bool operator!=(const ReverseIterator& other) const {
            return current != other.current;
        }

    private:
        typename map<int, vector<int>>::reverse_iterator current;
    };

    class ConstReverseIterator {
    public:
        explicit ConstReverseIterator(typename map<int, vector<int>>::const_reverse_iterator it)
            : current(it) {}

        const int& operator*() const { return current->first; }
        const int* operator->() const { return &(current->first); }

        ConstReverseIterator& operator++() {
            ++current;
            return *this;
        }

        ConstReverseIterator operator++(int) {
            ConstReverseIterator temp = *this;
            ++(*this);
            return temp;
        }

        ConstReverseIterator& operator--() {
            --current;
            return *this;
        }

        ConstReverseIterator operator--(int) {
            ConstReverseIterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const ConstReverseIterator& other) const {
            return current == other.current;
        }

        bool operator!=(const ConstReverseIterator& other) const {
            return current != other.current;
        }

    private:
        typename map<int, vector<int>>::const_reverse_iterator current;
    };

    Iterator begin() { return Iterator(registry.begin()); }
    Iterator end() { return Iterator(registry.end()); }

    ConstIterator cbegin() const { return ConstIterator(registry.cbegin()); }
    ConstIterator cend() const { return ConstIterator(registry.cend()); }

    ReverseIterator rbegin() { return ReverseIterator(registry.rbegin()); }
    ReverseIterator rend() { return ReverseIterator(registry.rend()); }

    ConstReverseIterator crbegin() const { return ConstReverseIterator(registry.crbegin()); }
    ConstReverseIterator crend() const { return ConstReverseIterator(registry.crend()); }

    template <typename Iter>
    void sortRange(Iter begin, Iter end) {
        sort(begin, end);
    }

    template <typename Iter, typename Value>
    void removeValueByKey(Iter mapBegin, Iter mapEnd, const int& key, const Value& value) {
        auto it = mapBegin;
        while (it != mapEnd) {
            if (it->first == key) {
                auto& values = it->second;
                auto valueIt = find(values.begin(), values.end(), value);

                if (valueIt != values.end()) {
                    values.erase(valueIt);
                    qDebug() << "Удалено значение " << value << " для клбча " << key;
                } else {
                    qDebug() << "Значение " << value << "для ключа не найдено " << key;
                }
                return;
            }
            ++it;
        }
        qDebug() << "Ключ " << key << " не найден";
    }

private:
    map<int, vector<int>> registry;
};

#endif //IDS_CONTAINER_H
