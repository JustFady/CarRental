/***********************************************************************************************************
* Project: Final Project
* File: source.cpp
* Authors: Fady H Youssef
* Date: March 05, 2021
* Description: This program will manage an inventory of cars and transactions for a car rental company.
* The two classes will be Car and Transaction. The information for the cars and transactions will be stored
* in a data file that will be used to populate the vectors that will contain the objects.
*************************************************************************************************************/
#include <iostream>
#include <string>
#include "Car.h"
#include <vector>

using namespace std;
//prototype functions
int mainMenu();
void addCar(vector<Car>& cInfo);
void viewCar(const vector<Car>& cInfo);
void viewCarInfo(const vector<Car>& cInfo);
void deleteCar(vector<Car>& cInfo);
void manageCars(vector<Car>& cInfo);
void editCar(vector<Car>& cInfo);
void menu(vector <Car>& cInfo);

/************************************************************
* Function: main
* Description:
*************************************************************/
int main()
{
	vector<Car> car;
	int choiceLI = 0;
	do
	{
		choiceLI = mainMenu();
		//if choice is more than 4 or less than 1, reset user
		while (choiceLI > 4 || choiceLI < 0)
		{
			cout << " " << endl;
			cout << "Invalid Option, Please try again: ";
			cin >> choiceLI;
		}
		//options menu functions
		switch (choiceLI)
		{
		case 1:
			break;
		case 2:
			addCar(car);
			break;
		case 3:
			manageCars(car);
			break;
		case 4:
			//transaction
			break;
		default:
			choiceLI = 0;
			break;
		}
	}
	//while choice isn't 0
	while (choiceLI != 0);
	cout << " " << endl;
	cout << "Thank you, Goodbye!" << endl;
}

/***********************************************
* Function: mainMenu
* Description: Menu for user to decide what they would like to do
* Return choice gets passed to main.
* Input: int choice - reads user choice from menu
***********************************************/
int mainMenu()
{
	int choice;
	cout << "||======================= Luxury Rent-a-Car =====================||" << endl;
	//list of options
	cout << "||===============================================================||" << endl;
	cout << "||          1 - Rent a Car                                       ||" << endl;
	cout << "||          2 - Add a Car                                        ||" << endl;
	cout << "||          3 - Manage Car Lot                                   ||" << endl;
	cout << "||          4 - Manage Transactions                              ||" << endl;
	cout << "||          0 - Exit                                             ||" << endl;
	cout << "||===============================================================||" << endl;
	cout << "Please Enter Choice: ";
	//reads user choice from menu
	while (!(cin >> choice)) {
		cout << "Please enter valid option above: ";
		cin.clear();
		cin.ignore(22, '\n');
	}
	return choice;
}
/***********************************************
* Function: manageCars
* Description: Menu for user to decide what they would like to do
* when the user decided to manage car lot from main()
* Input: int opt - reads user choice from menu
***********************************************/
void manageCars(vector<Car>& cInfo)
{
	int opt;
	{
		//list of options
		cout << endl;
		cout << "1 - View Available Cars" << endl;
		cout << "2 - Delete Car" << endl;
		cout << "3 - Edit Car" << endl;
		cout << "0 - Return to Main Menu" << endl;
		cout << "Please Enter Choice: ";
		//reads user choice from menu
		cin >> opt;
		while (opt < 0 || opt > 3) {
			cout << "Please enter invalid option: ";
			cin >> opt;
		}
		if (opt == 1)
		{
			viewCarInfo(cInfo);
		}
		else if (opt == 2)
		{
			deleteCar(cInfo);
		}
		else if (opt == 3)
		{
			editCar(cInfo);
		}
		else
		{
			cout << "Returning to Main Menu..." << endl;
		}
	}

}
/******************************************************************************
* Function: addCar
* Description: adds Cars to car lot and the data to storage from user input
* Input: string make - holds data for name of brand
* string model - holds data for name of model
* double rate - holds data for rate of car
* int vin - holds data for vin of car
* int year - holds data for year of car
********************************************************************************/
void addCar(vector<Car>& cInfo)
{
	string make;
	string model;
	double rate;
	long int vin;
	int year;
	int checkEqual = 0;

	cout << "\tPlease enter an 8 digit Vehicle Identification Number: ";
	cin >> vin;
	cin.clear();
	cin.ignore(100, '\n');
	while (vin > 99999999 || vin < 9999999)
	{
		cout << "\tVehicle Identification Number only 8 digit.\n\t Please enter valid number : ";
		cin >> vin;
		cin.clear();
		cin.ignore(100, '\n');
	}
	cout << "\tPlease enter Year of Car: ";
	cin >> year;
	cin.clear();
	cin.ignore(100, '\n');
	while (year > 2021 || year < 2015)
	{
		cout << "\tPlease enter car's year between 2015 - 2021: ";
		cin >> year;
		cin.clear();
		cin.ignore(100, '\n');
	}
	cout << "\tPlease enter Rate per hour: ";
	cin >> rate;
	cin.clear();
	cin.ignore(100, '\n');
	while (rate <= 0 || !rate)
	{
		cout << "\tPlease enter valid rate: ";
		cin >> rate;
		cin.clear();
		cin.ignore(100, '\n');
	}
	cout << "\tPlease enter Brand of Car: ";
	cin >> make;
	cin.ignore(100, '\n');
	cout << "\tPlease enter Model of Car: ";
	getline(cin, model);
	cInfo.push_back(Car(vin, make, model, rate, year));
	for (int i = 0; i < cInfo.size() - 1; i++)
	{
		if (cInfo.at(cInfo.size() - 1).equals(cInfo.at(i)) == 1)
			checkEqual = 1;
	}
	if (checkEqual == 1) {
		cout << "This Vehicle Identification Number is already in the lot.."
			<< endl << "Return to main menu";
		cInfo.pop_back();
	}
	else {
		cout << "Car Added to the Lot" << endl;
		cout << endl;
		menu(cInfo);
	}
	cout << endl;
	//displays car added
}
/****************************************************************
* Function: viewCar
* Description: displays available list of Cars
* Output: songName - list of available Cars in numerical order
****************************************************************/
void viewCar(const vector<Car>& cInfo)
{
	//if car lot less than 1 reset user
	if (cInfo.size() == 0)
	{
		cout << " " << endl;
		cout << "No Cars in list, Returning to main Menu..." << endl;
		cout << " " << endl;
		main();
	}
	//else display available cars
	else
	{
		cout << " " << endl;
		cout << "Available cars in Car lot: " << endl;
		for (int i = 0; i < cInfo.size(); i++)
		{
			cout << i << ". " << cInfo.at(i).getMake() << cInfo.at(i).getYear() << endl;
		}
	}
}
/****************************************************************************
* Function: viewCarInfo
* Description: displays Car chosen by user
* Input: int i - reads choice of cInfo data to grab for user
* Output: Car& cinfo - grabs Car information user desires and displays it.
*****************************************************************************/
void viewCarInfo(const vector<Car>& cInfo)
{
	//displays cars through overloaded << operator function
	viewCar(cInfo);
	int num;
	cout << "Which Car Information would you like to see: ";
	cin >> num;
	cin.clear();
	cin.ignore(100, '\n');
	while (num < 0 || num >= cInfo.size())
	{
		cout << "Input error. Please try again: ";
		cin >> num;
		cin.clear();
		cin.ignore(100, '\n');
	}
	cout << cInfo.at(num) << endl;
}
/****************************************************************************
* Function: deleteCar
* Description: deletes Car chosen by user
* Input: int i - reads choice of cInfo data to delete for user
* Output: Car& cinfo - grabs Car information user desires and deletes it.
*****************************************************************************/
void deleteCar(vector<Car>& cInfo)
{
	viewCar(cInfo);
	int num;
	cout << "Which car would you like to delete: ";
	cin >> num;
	cin.clear();
	cin.ignore(100, '\n');
	while (num < 0 || num >= cInfo.size())
	{
		cout << "Invalid. Please try again: ";
		cin >> num;
		cin.clear();
		cin.ignore(100, '\n');
	}
	//erase position which is the beginning of index + chosen number
	cInfo.erase(cInfo.begin() + num);
	cout << " " << endl;
	cout << "Car deleted, Returning to Main Menu..." << endl;
}
/****************************************************************************
* Function: editCar
* Description: edits Car chosen by user
* Input: int i - reads choice of cInfo data to edit for user
* string make - holds data for new name of brand
* string model - holds data for new name of model
* double rate - holds data for new rate of car
* int vin - holds data for new vin of car
* int year - holds data for new year of car
* Output: Car& cinfo - grabs Car information user desires and edits it.
*****************************************************************************/
void editCar(vector<Car>& cInfo)
{
	vector<Car> temp = cInfo;
	int i = 0;
	string make;
	string model;
	double rate;
	long int vin;
	int year;
	int checkEqual = 0;

	viewCar(cInfo);
	cout << "Which car would you like edit: ";
	cin >> i;
	//gets new vin of car
	cout << "\tPlease enter an 8 digit Vehicle Identification Number: ";
	cin >> vin;
	cin.clear();
	cin.ignore(100, '\n');
	while (vin > 99999999 || vin < 9999999)
	{
		cout << "\tVehicle Identification Number only 8 digit.\n\t Please enter valid number : ";
		cin >> vin;
		cin.clear();
		cin.ignore(100, '\n');
	}
	//get new year of car
	cout << "\tPlease enter Year of Car: ";
	cin >> year;
	cin.clear();
	cin.ignore(100, '\n');
	while (year > 2021 || year < 2015)
	{
		cout << "\tPlease enter car's year between 2015 - 2021: ";
		cin >> year;
		cin.clear();
		cin.ignore(100, '\n');
	}
	//enter new rate for rent
	cout << "\tPlease enter Rate per hour: ";
	cin >> rate;
	cin.clear();
	cin.ignore(100, '\n');
	while (rate <= 0 || !rate)
	{
		cout << "\tPlease enter invalid rate: ";
		cin >> rate;
		cin.clear();
		cin.ignore(100, '\n');
	}
	//gets new brand of car
	cout << "\tPlease enter Brand of Car: ";
	cin >> make;
	cin.ignore(100, '\n');
	//gets new model of car
	cout << "\tPlease enter Model of Car: ";
	getline(cin, model);
	for (int i = 0; i < temp.size() - 1; i++)
	{
		if (temp.at(temp.size() - 1).equals(temp.at(i)) == 1)
			checkEqual = 1;
	}
	if (checkEqual == 1) {
		cout << "This Vehicle Identification Number is already in the lot.." << endl << endl;
		cInfo.pop_back();
	}
	cout << endl;
	//sets all new data
	temp.at(i).setMake(make);
	temp.at(i).setYear(year);
	temp.at(i).setRate(rate);
	temp.at(i).setVin(vin);
	temp.at(i).setModel(model);
	//check if car was previously added through vin
	for (int i = 0; i < temp.size() - 1; i++)
	{
		if (temp.at(temp.size() - 1).equals(temp.at(i)) == 1)
			checkEqual = 1;
	}
	if (checkEqual == 1) {
		cout << "This Vehicle Identification Number is already in the lot.." << endl << endl;
		cout << "Fail to edit. Duplicate Vin Number" << endl;
	}
	//if information is new then save all data
	else  cInfo.at(i) = temp.at(i);

	cout << endl;
	//adds car to car lot
	cout << "VIN: " << vin << " - "
		<< make << " " << model
		<< "(" << year << ") "
		<< "has been added to the car lot" << " for "
		<< "$" << rate << "/hr" << endl;
	cout << endl;
	menu(cInfo);
}
/***********************************************
* Function: menu
* Description: Menu for user to decide what they would like to do
* after they add or edit a car
* Input: int choice - reads user choice from menu
***********************************************/
void menu(vector <Car>& cInfo)
{
	int choice;
	//option menu
	cout << "1 - Add New Car" << endl;
	cout << "2 - Manage Car Lot" << endl;
	cout << "Press any Key to return to Main Menu" << endl;
	cout << "Please enter your choice: ";
	cin >> choice;
	//option menu functions
	if (choice == 1)
	{
		addCar(cInfo);
	}
	else if (choice == 2)
	{
		manageCars(cInfo);
	}
}
