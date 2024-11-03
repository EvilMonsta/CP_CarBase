#ifndef MARKS_TRANSPORT_ID_CONTAINER_H
#define MARKS_TRANSPORT_ID_CONTAINER_H
#include <map>
#include <vector>
#include "mark.h"
#include<iostream>
using namespace std;

template <typename VehicleType>
class MarksTransportIdContainer {
public:
    void addVehicleId(const Mark& mark, int vehicleId) {
        registry[mark.id].push_back(vehicleId);
    }

    const vector<int> getOneTypeVehicleIds(int markId) const {
        // return registry.at(markId);
        vector<int> ids;

        auto it = registry.find(markId); // Ищем markId в registry
        if (it != registry.end()) {
            ids = it->second; // Если найден, возвращаем копию вектора
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

    void printRegistry() const {
        for (const auto& pair : registry) {
            std::cout << "Mark ID: " << pair.first << " - Vehicle IDs: ";
            for (int id : pair.second) {
                std::cout << id << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    map<int, vector<int>> registry;
};

#endif //MARKS_TRANSPORT_ID_CONTAINER_H
