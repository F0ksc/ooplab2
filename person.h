#ifndef person.h // (3)Пункт 1

#include <iostream>
#include <string>

class Person {
protected:
	std::string name;// (3)Пункт 2
	long long phone;
public:
	Person(std::string name, long long phone); // (3)Пункт 5
	Person();
	Person(const Person& other);
	std::string getName() const;
	void printInfo();

	virtual ~Person(); // (3)Пункт 8
};

#endif // person.h