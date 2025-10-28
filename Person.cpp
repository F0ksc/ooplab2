#include "Person.h"
#include <iostream> // (3)Пункт 1

using namespace std;

Person::Person(string name, long long phone) : name(name), phone(phone) { // (3)Пункт 5
	cout << "Person " << this->name << " created" << endl; // (3)Пункт 7 
}

Person::Person() : name("Unnamed"), phone(0LL) {
	cout << "Empty person created" << endl;
}

Person::Person(const Person& other) {
	name = other.name;
	phone = other.phone;
}

string Person::getName() const {
	return this->name;
}

void Person::printInfo() {
	cout << "Name: " << this->name << " Phone: " << this->phone << endl;
}

Person::~Person() { // (3)Пункт 8 
	cout << "Person " << this->name << " deleted" << endl; // (3)Пункт 7
}