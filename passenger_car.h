#ifndef PASSENGER_CAR_H
#define PASSENGER_CAR_H
#include<car.h>


class PassengerCar : public Car {
public:

    int numberOfSeats;

    PassengerCar() : Car() {};

    PassengerCar(int id, Mark* mark, const string& model, const string& generation, int produceDate,
                const string& transmissionType, double engineCapacity,
                int numberOfSeats) :
    Car(id, mark, model, generation, produceDate, transmissionType, engineCapacity),
        numberOfSeats(numberOfSeats) {}

    ~PassengerCar(){};

};

#endif // PASSENGER_CAR_H
