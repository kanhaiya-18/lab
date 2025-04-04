#include <iostream>
using namespace std;

class Vehicle {
protected:
    int wheels;
    string typeOfFuel;

public:
    void setData() {
        cout << "Enter the number of wheels (e.g., 2, 4, 6): ";
        cin>>wheels;
        cout << "Enter the type of fuel (e.g., Petrol, Diesel, Electric): ";
        cin >> typeOfFuel;
    }

    void show() {
        cout << "Number of wheels: " << wheels << endl;
        cout << "Fuel type: " << typeOfFuel << endl;
    }
};

class Car : public Vehicle {
protected:
    string typeOfCar;

public:
    void setData() {
        Vehicle::setData();
        cout << "Enter type of car: ";
        cin >> typeOfCar;
    }

    void show() {
        Vehicle::show();
        cout << "Type of car: " << typeOfCar << endl;
    }

};

class SUV : public Car {
private:
    int totseats;

public:
    void setData() {
        Car::setData();
        cout << "Enter total seats in the SUV : ";
        cin>>totseats;
    }

    void show() {
        Car::show();
        cout << "Total seats in the SUV: " << totseats << endl;
        if (totseats > 5) {
            cout << "This is a large SUV!" << endl;
        } else {
            cout << "This is a compact SUV!" << endl;
        }
    }
};

int main() {
    SUV mySUV;
    int choice;

    do {
        cout << "\nMenu: \n";
        cout << "1. Set Vehicle Data\n";
        cout << "2. Show Vehicle Data\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            mySUV.setData();
            break;
        case 2:
            mySUV.show();
            break;
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice, please try again!" << endl;
        }
    } while (choice != 0);

    return 0;
}

