/***********************************************************************************
 *  Project: Lab 6
 *  File: Car.cpp
 *  Authors: Fady H Youssef
 *  Date: March 05, 2021
 ***************************************************************/
#include "Car.h"

using namespace std;

/****************************************************************************
* Function: Car
* Description: default constructor(sets all data members to default 0
*************************************************************************/
Car::Car()
{
	Car::vin = 0;
	Car::make = "";
	Car::model = "";
	Car::rate = 0;
	Car::year = 0;
	Car::numCars = 0;
}
/*****************************************************************************
 * Function: Car
 * Description: A constructor that assigns all data members.
 * Input: int vin - VIN of the car
 *        string - model of the car
 *        double - rate how much the car cost to rent
 *        int year - year of the car
 * Output: None
 ****************************************************************************/
Car::Car(int vin, string make, string model, double rate, int year)
{
	setVin(vin);
	setMake(make);
	setModel(model);
	setRate(rate);
	setYear(year);
}
/***********************************************
* Function: getVin
* Description : gets integer of vin
* Output : integer of vin
******************************************/
int Car::getVin() const
{
	return vin;
}

/***********************************************
* Function: getNumCars
* Description : gets integer of number of car
* Output : integer of numCars
******************************************/
int Car::getNumCars() const
{
	return numCars;
}
/*************************************
* Function: setVin
* Description: sets integer of vin
* Input: integer of vin
**************************************/
void Car::setVin(int vin)
{
	this->vin = vin;
}
/**************************************
* Function: getMake
* Description : gets string of make
* output : string of make
*************************************/
string Car::getMake() const
{
	return make;
}
/************************************
* Function: setMake
* Description: sets string of make
* Input: The name of make
************************************/
void Car::setMake(string make)
{
	this->make = make;
}
/******************************************
* Function: getmodel
* Description : gets string of model
* output : string of model
****************************************/
string Car::getModel() const
{
	return model;
}
/**************************************
* Function: setModel
* Description: sets string of model
* Input: The name of model
*****************************************/
void Car::setModel(string model)
{
	this->model = model;
}
/*****************************************
* Function: getYear
* Description : gets integer of year
* output : integer of year
*********************************************/
int Car::getYear() const
{
	return year;
}
/*****************************************
* Function: setYear
* Description: sets integer of year
* Input: Year of car
**************************************/
void Car::setYear(int year)
{
	this->year = year;
}
/********************************************
* Function: getRate
* Description : gets double of rate
* output : double rate
********************************************/
double Car::getRate() const
{
	return rate;
}
/*******************************************
* Function: setRate
* Description: sets double of rate
* Input: rate of car
********************************************/
void Car::setRate(double rate)
{
	this->rate = rate;
}
/***********************************************
* Function: decrementNumCars
* Description : decrements the cars in lot
* output : numCars - 1
********************************************/
void Car::decrementNumCars()
{
	numCars--;
}
/*********************************************************************
* Function: equals
* Description: checks if vin is same as one already in lot
* Input: svin
* output: whether or not vin input is similar to previous input
***********************************************************************/
bool Car::equals(const Car& c)
{
	if (vin == c.vin)
		return true;
	return false;
}
/****************************************************************
* Function: operator<<
* Description: Overloaded the stream out operator to display data
* Input: output - the ostream output being modified
		 Car - class car being display
* output: the ostream being modified
**********************************************************************/
ostream& operator<<(ostream& output, Car c)
{
	output << "\tVehicle Identification Number: " + to_string(c.vin) + "\n\tName of Brand: " + c.make + "\n\tName of Model: "
		+ c.model + "\n\tYear of Car: " + to_string(c.year) + "\n --> Rate of Car: " + to_string(c.rate) + "\n";
	return output;
}
/*******************************************
* Function: setRate
* Description: sets number of Car in the lot
* Input: numsCar
********************************************/
void Car::setNumCars(int numsCar)
{
	this->numCars = numsCar;
}


