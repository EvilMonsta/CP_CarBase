#ifndef PASSENGER_CAR_H
#define PASSENGER_CAR_H
#include<car.h>


class PassengerCar : public Car {
public:

    int numberOfSeats;

    PassengerCar() : Car() {};

    PassengerCar(int id, Mark* mark, const string& model, int produceDate,
                const string& transmissionType, double engineCapacity,
                int numberOfSeats) :
    Car(id, mark, model, produceDate, transmissionType, engineCapacity),
        numberOfSeats(numberOfSeats) {}

    ~PassengerCar(){};

    void printData() const override;

};

#endif // PASSENGER_CAR_H
