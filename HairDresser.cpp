// Пункт 15 // Пункт 13

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "HAIRDRESSER.h"

using namespace std;

	// Пункт 4 // Пункт 13

	void customer::creatingCustomer(string name, double phone, int membershipId, string id, bool membership, bool elder) {
		this->name = name;
		this->phone = phone;
		this->membershipId = membershipId;
		spent = 0;
		membershipPoints = 0;
		this->id = id;
		this->membership = membership;
		this->elder = elder;
	}

	void customer::updatePhonenumber(int newPhone) {
		phone = newPhone;
	}
	void customer::addSpent(int amount, bool elder) {
		spent += amount / 3;
		membershipPoints += amount / 20;
	}

	void customer::addSpent(int amount, bool elder, bool usingPoints) {
		membershipPoints -= amount / 3;
	}

	void customer::eldereligible(int age) {
		if (age >= 60) {
			elder = true;
		}
	}

	void customer::merge(customer dublicate) {
		spent += dublicate.spent;
		membershipPoints += dublicate.membershipPoints;
	}

	customer customer::referalLink(string name, string id, double phone) {
		customer newCustomer;
		newCustomer.name = name;
		newCustomer.id = id;
		newCustomer.phone = phone;
		newCustomer.membership = true;
		newCustomer.membershipPoints = 200;
		return newCustomer;
	}

	// Пункт 5 // Пункт 13

	void customer::loadInFile() {
		ofstream txt("customerinfo.txt");
		txt << name << " " << phone << " " << membershipId << " " << spent << " " << membershipPoints << " " << id << " " << membership << " " << elder << endl;
		txt.close();
	}

	void customer::loadFromFile() {
		ifstream txt("customerinfo.txt");
		txt >> name >> phone >> membershipId >> spent >> membershipPoints >> id >> membership >> elder;
		txt.close();
	}

	void customer::randomPurchases() { // Пункт 12 // Пункт 13
		int size = (rand() % 10) + 12;
		int* randPurchases = new int[size];

		for (int i = 0; i < size; i++) {
			randPurchases[i] = (rand() % 100) + 10;
			cout << randPurchases[i] << " ";
		}
		cout << endl;

		sort(randPurchases, randPurchases + size);

		cout << "Sorted" << endl;
		for (int i = 0; i < size; i++) {
			cout << randPurchases[i] << " ";
		}
		cout << endl;
	}

	// Пункт 4 // Пункт 13

	void hairDresser::creatingHD(string id, int exp, int hourRate, bool canColor, string name, int workstation) {
		employeeId = id;
		exp = exp;
		this->hourRate = hourRate;
		this->canColor = canColor;
		this->name = name;
		this->workstation = workstation;
		available = true;
	}

	void hairDresser::printSchedule() {
		cout << "Schedule: " << "10:00 - 17:00" << endl;
	}

	void hairDresser::assignClient(customer client) {
		currentClient = client;
	}

	double hairDresser::calculateCost(int hours) {
		return hours * hourRate;
	}

	double hairDresser::calculateCost(int hours, int productFee) {
		return (hours * hourRate) + productFee;
	}

	int hairDresser::experience() {
		return exp;
	}

	void hairDresser::experience(int change) {
		exp = change;
	}

	customer hairDresser::finalTouches(customer hotNReady)
	{
		customer temp = currentClient;
		currentClient.id = "None";
		return temp;
	}

	void hairDresser::loadInFile() {
		ofstream txt("hairDresserinfo.txt");
		txt << employeeId << " " << name << " " << workstation << " " << exp << " " << hourRate << " " << canColor << " " << available << endl;
		txt.close();
	}

	void hairDresser::loadFromFile() {
		ifstream txt("hairDresserinfo.txt");
		txt >> employeeId >> name >> workstation >> exp >> hourRate >> canColor >> available;
		txt.close();
	}