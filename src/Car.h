
/***********************************************************************************************************
* Project: Final Project
* File: Car.h
* Authors: Fady H Youssef 
* Date: March 05, 2021
* Description: This is the header file for the Car Class
*************************************************************************************************************/
#ifndef _CAR_H
#define _CAR_H

#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;
/********************************************************
* Class: Car
* Description: This class adds, deletes, and edits
* Data members:
* vin - Vehicle Identification Number
* make - name for brand of car
* model - name for model of car
* rate - rate of care per hour
* year - year car was created
* numCars - number of cars in lot
*********************************************************/
class Car
{
	friend std::ostream& operator<<(std::ostream& output, Car c);
private:
	//Private data memebers
	int vin;
	string make;
	string model;
	double rate;
	int year;
	int numCars;
public:
	//Public fuctions in class
	Car();
	Car(int vin, string make, string model, double rate, int year);
	void setNumCars(int numsCars);
	int getNumCars() const;
	int getVin() const;
	void setVin(int vin);
	string getMake() const;
	void setMake(string make);
	string getModel() const;
	void setModel(string model);
	int getYear() const;
	void setYear(int year);
	double getRate() const;
	void setRate(double rate);
	bool equals(const Car& c);
	void decrementNumCars();
};
#endif 	
