// ����� 15 // ����� 13

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class customer { // ����� 1 // ����� 13
private: // ����� 2 // ����� 13
	string name;
	int phone;
	int membershipId;
	int spent;
	int membershipPoints;
public:
	string id;
	bool membership;
	bool elder;

	// ����� 4 // ����� 13

	void creatingCustomer(string name, double phone, int membershipId, string id, bool membership, bool elder) {
	}

	void updatePhonenumber(int newPhone) {
	}
	void addSpent(int amount, bool elder) {
	}

	void addSpent(int amount, bool elder, bool usingPoints) {
	}

	void eldereligible(int age) {
	}

	void merge(customer dublicate) {
	}

	customer referalLink(string name, string id, double phone) {
	}

	// ����� 5 // ����� 13

	void loadInFile() {
	}

	void loadFromFile() {
	}

	void randomPurchases() { // ����� 12 // ����� 13
	}
};

class hairDresser { // ����� 1 // ����� 13
private: // ����� 2 // ����� 13
	string employeeId;
	customer currentClient; // ����� 3 // ����� 13
	int exp;
	int hourRate;
	bool canColor;
public:
	string name;
	int workstation;
	bool available;

	// ����� 4 // ����� 13

	void creatingHD(string id, int exp, int hourRate, bool canColor, string name, int workstation) {
	}

	void printSchedule() {
	}

	void assignClient(customer client) {
	}

	double calculateCost(int hours) {
	}

	double calculateCost(int hours, int productFee) {
	}

	int experience() {
	}

	void experience(int change) {
	}

	customer finalTouches(customer hotNReady)
	{
	}

	void loadInFile() {
	}

	void loadFromFile() {
	}
};