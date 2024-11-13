#ifndef MARKS_TRANSPORT_ID_CONTAINER_H
#define MARKS_TRANSPORT_ID_CONTAINER_H
#include <map>
#include <vector>
#include "mark.h"
#include<iostream>
#include<fstream>
#include<QDebug>
using namespace std;

template <typename VehicleType>
class MarksTransportIdContainer {
public:
    void addVehicleId(const Mark& mark, int vehicleId) {
        registry[mark.id].push_back(vehicleId);
        qDebug() << "successful";
        qDebug() << mark.id;
    }

    const vector<int> getOneTypeVehicleIds(int markId) const {
        vector<int> ids;

        auto it = registry.find(markId);
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
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "unable to open file: " << filename << endl;
            return false;
        }

        for (const auto& [markId, ids] : registry) {
            file << markId << ":";
            for (size_t i = 0; i < ids.size(); ++i) {
                file << ids[i];
                if (i < ids.size() - 1) file << ",";
            }
            file << "\n";
        }
        file.close();
        return true;
    }

    bool loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Unable to open file: " << filename << endl;
            return false;
        }

        registry.clear();

        string line;
        while (getline(file, line)) {
            size_t colonPos = line.find(':');
            if (colonPos == string::npos) continue;

            int markId = stoi(line.substr(0, colonPos));
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

            registry[markId] = ids;
        }

        file.close();
        return true;
    }

private:
    map<int, vector<int>> registry;
};

#endif //MARKS_TRANSPORT_ID_CONTAINER_H
