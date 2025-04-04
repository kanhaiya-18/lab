#include<iostream>
using namespace std;

class Vehicle
{
	int wheels;
	string typeOfFuel;
	public:
	void setData()
	{
		cout<<"enter the number of wheels and type of fuel\n";
		cin>>wheels;
		cin>>typeOfFuel;
	}
	void show()
	{
		cout<<"the number of wheels of the vehicle is : "<<wheels<<endl;
		cout<<"the fuel type is: "<<typeOfFuel<<endl;
	}
};
class Car : public Vehicle
{
	string typeOfCar;
	public: 
	void setData()
	{
		Vehicle::setData();
		cout<<"enter type of car\n";
		cin>>typeOfCar;
	}
	void show()
	{
		Vehicle::show();
		cout<<"type of car : "<<typeOfCar<<endl;
	}
};
class SUV: public Car
{
	int totseats;
	public: 
	void setData()
	{
		Car::setData();
		cout<<"enter the seats: "<<endl;
		cin>>totseats;
	}
	void show()
	{
		Car::show();
		cout<<"the total seats in the car is : "<<totseats<<endl;
	}
};
int main()
{
	SUV c;
	c.setData();
	c.show();
	return 0;
}
