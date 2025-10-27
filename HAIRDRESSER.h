// Пункт 15 // Пункт 13

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class customer { // Пункт 1 // Пункт 13
private: // Пункт 2 // Пункт 13
	string name;
	long long phone;
	int membershipId;
	int spent;
	int membershipPoints;
	static int totalCustomers;	// Пункт (2)4
public:
	string id;
	bool membership;
	bool elder;

	// Пункт 4 // Пункт 13
	static int getTotalCustomers();	// Пункт (2)4
		
	customer();	// Пункт (2) 1

	customer(string name, long long phone, int membershipId, string id, bool membership, bool elder);	// Пункт (2)1

	customer(const customer& other);	// Пункт (2)1

	void updatePhonenumber(int newPhone);
	void addSpent(int amount, bool elder);

	void addSpent(int amount, bool elder, bool usingPoints);

	void eldereligible(int age);

	void merge(customer dublicate);

	customer referalLink(string name, string id, double phone);

	// Пункт 5 // Пункт 13

	void loadInFile();

	void loadFromFile();

	void randomPurchases(); // Пункт 12 // Пункт 13
	

	~customer();	// Пункт (2)3
};

class hairDresser { // Пункт 1 // Пункт 13
private: // Пункт 2 // Пункт 13
	string employeeId;
	customer currentClient; // Пункт 3 // Пункт 13 // Пункт (2) 13
	int exp;
	int hourRate;
	bool canColor;
public:
	string name;
	int workstation;
	bool available;

	// Пункт 4 // Пункт 13

	void creatingHD(string id, int exp, int hourRate, bool canColor, string name, int workstation);

	void printSchedule();

	void assignClient(customer client);

	double calculateCost(int hours);

	double calculateCost(int hours, int productFee);

	int experience();

	void experience(int change);

	customer finalTouches(customer hotNReady);

	void loadInFile();

	void loadFromFile();

	~hairDresser();	// Пункт (2)3
};

// Пункт (2) 12 ->

class Barbershop {
public:
	hairDresser* staff[5];
	int numStaff;

	Barbershop() : numStaff(0) {
		for (int i = 0; i < 5; ++i) {
			staff[i] = nullptr;
		}
	}

	void hireHairdresser(hairDresser* hd_pointer);

	void showStaff();
};

//  <- Пункт (2) 12