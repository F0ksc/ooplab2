// Пункт 15 // Пункт 13

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Person.h"

class customer : public Person { // Пункт 1 // Пункт 13 // (3)Пункт 1
private: // Пункт 2 // Пункт 13
	int membershipId;
	int spent;
	int membershipPoints;
	static int totalCustomers;	// Пункт (2)4
public:
	std::string id;
	bool membership;
	bool elder;

	// Пункт 4 // Пункт 13
	static int getTotalCustomers();	// Пункт (2)4
		
	customer();	// Пункт (2) 1

	customer(std::string name, long long phone, int membershipId, std::string id, bool membership, bool elder);	// Пункт (2)1 // (3)Пункт 5

	customer(const customer& other);	// Пункт (2)1

	void updatePhonenumber(int newPhone);

	std::string getId() const;

	void printDetails();

	void addSpent(double amount, bool elder);

	void addSpent(double amount, bool elder, bool usingPoints);

	void eldereligible(int age);

	void merge(customer dublicate);

	customer referalLink(std::string name,long long phone, std::string id);

	// Пункт 5 // Пункт 13

	void loadInFile();

	void loadFromFile();

	void randomPurchases(); // Пункт 12 // Пункт 13
	

	~customer();	// Пункт (2)3
};

class hairDresser : public Person { // Пункт 1 // Пункт 13
private: // Пункт 2 // Пункт 13
	std::string employeeId;
	customer currentClient; // Пункт 3 // Пункт 13 // Пункт (2) 13
	int exp;
	int hourRate;
	bool canColor;
public:
	int workstation;
	bool available;

	// Пункт 4 // Пункт 13

	hairDresser(std::string name, long long phone, std::string id, int exp, int hourRate, bool canColor, int workstation);

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

class Barbershop : public Person{
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

class ClientRecord : private customer { // (3)Пункт 3
public:
	using customer::id; // (3)Пункт 6
	using customer::addSpent; // (3)Пункт 6
	using customer::printDetails; // (3)Пункт 6

	ClientRecord(std::string name, long long phone, int mID, std::string id);
};

class Accountant {
public:
	void calculateSalary();
};

class Manager : public hairDresser, public Accountant { // (3)Пункт 4
public:
	Manager(std::string name, long long phone, std::string empId, int hourRate);

};