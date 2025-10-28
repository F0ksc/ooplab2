// ����� 15 // ����� 13

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Person.h"

class customer : public Person { // ����� 1 // ����� 13 // (3)����� 1
private: // ����� 2 // ����� 13
	int membershipId;
	int spent;
	int membershipPoints;
	static int totalCustomers;	// ����� (2)4
public:
	std::string id;
	bool membership;
	bool elder;

	// ����� 4 // ����� 13
	static int getTotalCustomers();	// ����� (2)4
		
	customer();	// ����� (2) 1

	customer(std::string name, long long phone, int membershipId, std::string id, bool membership, bool elder);	// ����� (2)1 // (3)����� 5

	customer(const customer& other);	// ����� (2)1

	void updatePhonenumber(int newPhone);

	std::string getId() const;

	void printDetails();

	void addSpent(double amount, bool elder);

	void addSpent(double amount, bool elder, bool usingPoints);

	void eldereligible(int age);

	void merge(customer dublicate);

	customer referalLink(std::string name,long long phone, std::string id);

	// ����� 5 // ����� 13

	void loadInFile();

	void loadFromFile();

	void randomPurchases(); // ����� 12 // ����� 13
	

	~customer();	// ����� (2)3
};

class hairDresser : public Person { // ����� 1 // ����� 13
private: // ����� 2 // ����� 13
	std::string employeeId;
	customer currentClient; // ����� 3 // ����� 13 // ����� (2) 13
	int exp;
	int hourRate;
	bool canColor;
public:
	int workstation;
	bool available;

	// ����� 4 // ����� 13

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

	~hairDresser();	// ����� (2)3
};

// ����� (2) 12 ->

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

//  <- ����� (2) 12

class ClientRecord : private customer { // (3)����� 3
public:
	using customer::id; // (3)����� 6
	using customer::addSpent; // (3)����� 6
	using customer::printDetails; // (3)����� 6

	ClientRecord(std::string name, long long phone, int mID, std::string id);
};

class Accountant {
public:
	void calculateSalary();
};

class Manager : public hairDresser, public Accountant { // (3)����� 4
public:
	Manager(std::string name, long long phone, std::string empId, int hourRate);

};