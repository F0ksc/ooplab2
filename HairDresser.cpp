// Пункт 15 // Пункт 13

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "HAIRDRESSER.h"

using namespace std;

	// Пункт 4 // Пункт 13
int customer::totalCustomers = 0;

	int customer::getTotalCustomers() {	// Пункт (2)4
		return totalCustomers;
	}

	customer::customer() {	// Пункт (2)1
		name = "Unnamed";
		phone = 0;
		membershipId = 0;
		spent = 0;
		membershipPoints = 0;
		id = "NONE";
		membership = false;
		elder = false;
		totalCustomers++;
	}

	customer::customer(string name, long long phone, int membershipId, string id, bool membership, bool elder)	// Пункт (2)1
		: name(name),
		phone(phone),
		membershipId(membershipId),
		id(id),
		membership(membership),
		elder(elder)
	{
		spent = 0;
		membershipPoints = 0;
		totalCustomers++;
	}

	customer::customer(const customer& other) {	// Пункт (2)1
		name = other.name;
		phone = other.phone;
		membershipId = other.membershipId;
		spent = other.spent;
		membershipPoints = other.membershipPoints;
		id = other.id;
		membership = other.membership;
		elder = other.elder;
		totalCustomers++;
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
		totalCustomers++;
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

	void hairDresser::assignClient(customer client) { // Пункт (2) 13
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

	customer::~customer() {	// Пункт (2) 3 
		cout << "Customer " << name << " with ID " << id << " is deleted." << endl;
		totalCustomers--;
	}

	hairDresser::~hairDresser() {	// Пункт (2) 3
		cout << "Hairdresser " << name << " with Employee ID " << employeeId << " is deleted." << endl;
	}

	void Barbershop::showStaff() {
		cout << "  Personnel  " << endl;
		for (int i = 0; i < numStaff; ++i) {
			cout << " - " << staff[i]->name << endl;
		}
	}

	void Barbershop::hireHairdresser(hairDresser* hd_pointer) {
		if (numStaff < 5) {
			staff[numStaff] = hd_pointer;
			numStaff++;
		}
	}