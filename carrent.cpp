#include <iostream>
#include <string>

using namespace std;

class CarRental {
private:
    int carID;
    string carType;
    bool isRented[30];

public:
    CarRental(int id, string type) : carID(id), carType(type) {
        for (int i = 0; i < 30; ++i) {
            isRented[i] = false;
        }
    }

    int getID() const {
        return carID;
    }

    string getType() const {
        return carType;
    }

    bool rentCar(int startDate, int endDate) {
        if (startDate < 0 || startDate > 29 || endDate < 0 || endDate > 29 || startDate > endDate) {
            cout << "Invalid date range." << endl;
            return false;
        }

        for (int i = startDate; i <= endDate; ++i) {
            if (isRented[i]) {
                cout << "Car is already rented for some dates." << endl;
                return false;
            }
            isRented[i] = true;
        }

        return true;
    }

    bool returnCar(int startDate, int endDate) {
        if (startDate < 0 || startDate > 29 || endDate < 0 || endDate > 29 || startDate > endDate) {
            cout << "Invalid date range." << endl;
            return false;
        }

        for (int i = startDate; i <= endDate; ++i) {
            isRented[i] = false;
        }

        return true;
    }

    void viewAvailability() {
        cout << "Car ID: " << carID << ", Car Type: " << carType << endl;
        cout << "Availability:" << endl;
        for (int i = 0; i < 30; ++i) {
            if (!isRented[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }

    static double calculateRentalRate(CarRental* cars[], int numCars) {
        int totalDays = 30 * numCars;
        int rentedDays = 0;

        for (int i = 0; i < numCars; ++i) {
            for (int j = 0; j < 30; ++j) {
                if (cars[i]->isRented[j]) {
                    rentedDays++;
                }
            }
        }

        return (double)rentedDays / totalDays;
    }
};

class LuxuryCar : public CarRental {
private:
    string* luxuryFeatures;
    int numFeatures;

public:
    LuxuryCar(int id, string type, string* features, int numFeatures)
        : CarRental(id, type), luxuryFeatures(features), numFeatures(numFeatures) {}

    void viewAvailability()  {
        CarRental::viewAvailability();
        cout << "Luxury Features:" << endl;
        for (int i = 0; i < numFeatures; ++i) {
            cout << "- " << luxuryFeatures[i] << endl;
        }
    }
};

int main() {
    CarRental* cars[3];
    cars[0] = new CarRental(101, "Sedan");
    cars[1] = new CarRental(102, "SUV");
    string luxuryFeatures[] = {"Leather Seats", "Sunroof"};
    cars[2] = new LuxuryCar(103, "Hatchback", luxuryFeatures, 2);

    cars[0]->rentCar(1, 5);
    cars[1]->rentCar(10, 15);
    cars[2]->rentCar(20, 25);

    cars[0]->returnCar(3, 4);

    cars[0]->viewAvailability();
    cars[1]->viewAvailability();
    cars[2]->viewAvailability();

    double rentalRate = CarRental::calculateRentalRate(cars, 3);
    cout << "Overall Rental Rate: " << rentalRate << endl;


    for (int i = 0; i < 3; ++i) {
        delete cars[i];
    }

    return 0;
}
