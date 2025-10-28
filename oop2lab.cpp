// Пункт 15 // Пункт 13

#include <iostream>
#include <fstream>
#include "HAIRDRESSER.h"

using namespace std;

void recalculation(customer c, int hours) {	// Пункт (2)5
	cout << "Using copy of customer with ID: " << c.id << endl;
	c.addSpent(hours * 50, c.elder);
}

void recalculation(customer* c, int hours) {	// Пункт (2)6
	cout << "Using address of customer with ID: " << c->id << endl;
	c->addSpent(hours * 50, c->elder);
}

int main()
{
	Barbershop shop; // Пункт (2) 12

	customer client1, client2, client3, client4, client5; // Пункт 6 // Пункт 13
	
	// Пункт 6 // Пункт 13

	customer* dynamicClient1 = new customer(); // Пункт (2) 9
	customer* dynamicClient2 = new customer();
	customer* dynamicClient3 = new customer();
	customer* dynamicClient4 = new customer();
	customer* dynamicClient5 = new customer();

	customer* pclient = &client1; // Пункт (2)9

	customer* dClient1 = new customer(); 	// Пункт (2)1 8
	cout << "Creating Dclient2 " << endl;
	customer* dClient2 = new customer("Eve", 1122334455, 1002, "C003", true, false);	// Пункт (2)1 8
	customer* dClient3 = new customer(*dClient2);	// Пункт (2)1 8

	hairDresser hd1("Alice", 1234567890, "HD001", 5, 50, true, 1);

	Manager mngr1("Bob", 9988776655, "M001", 70);

	int hairProductsPrices[10] = { 15, 25, 35, 45, 55, 65, 75, 85, 95, 105 }; // Пункт 7 // Пункт 13
	string hairProductsNames[10] = { "Shampoo", "Conditioner", "Hair Gel", "Hair Spray", "Hair Wax", "Hair Mousse", "Leave-in Conditioner", "Hair Serum", "Heat Protectant", "Hair Oil" }; // Пункт 7

	for (int i = 0; i < 10; i++) { 
		cout << "Product: " << hairProductsNames[i] << ", Price: " << hairProductsPrices[i] << endl; // Пункт 8	 // Пункт 13
	}
	
	int productNum = 0;
	cin >> productNum;

	// Пункт 9 -> // Пункт 13

	cout << "Amount of customers done " <<customer::getTotalCustomers() << endl; // Пункт (2)4

	client1.merge(client2);

	client1.eldereligible(65);
	pclient->updatePhonenumber(880055535); // Пункт 11 // Пункт 13

	client1.referalLink("Charlie", 9876543210, "C002"); // Пункт (2) 7

	hd1.printSchedule();

	// Пункт 10 -> // Пункт 13
	hd1.assignClient(client1); // Пункт (2) 11 // Пункт (2) 13
	cout << "Hairdresser " << hd1.getName() << " is assigned to client with ID: " << client1.id << endl;
	
	hd1.experience(4);
	cout << "Hairdresser " << hd1.getName() << " has " << hd1.experience() << " years of experience" << endl;
	// <- Пункт 10 // Пункт 13 

	if (productNum > 0 && productNum < 11) {
		hd1.calculateCost(2, hairProductsPrices[productNum - 1]);
		client1.addSpent(hd1.calculateCost(2, hairProductsPrices[productNum - 1]), client1.elder);
	}
	else {
		hd1.calculateCost(2);
		client1.addSpent(hd1.calculateCost(2), client1.elder);
	}

	recalculation(client1, 2); // Пункт (2)5
	recalculation(&client1, 2); // Пункт (2)6

	shop.hireHairdresser(&hd1); // Пункт (2) 12

	hd1.loadInFile();
	client1.loadInFile();

	customer finishedClient = hd1.finalTouches(client1); // Пункт (2) 7
	cout << "Client with ID: " << finishedClient.id << " has completed their appointment." << endl;

	client1.randomPurchases(); // Пункт 12 // Пункт 13

	ClientRecord rec("Dima", 555LL, 1002, "R001");

	rec.printDetails();

	rec.addSpent(200.0, false);
	
	mngr1.printInfo();
	mngr1.experience();
	mngr1.calculateSalary();

	// <- Пункт 9 // Пункт 13

	delete dClient1;	// Пункт (2)3
	cout << "Deleting Dclient " << endl;
	delete dClient2;	// Пункт (2)3
	delete dClient3;	// Пункт (2)3
	delete dynamicClient1;	// Пункт (2)3
	delete dynamicClient2;	// Пункт (2)3
	delete dynamicClient3;	// Пункт (2)3
	delete dynamicClient4;	// Пункт (2)3
	delete dynamicClient5;	// Пункт (2)3
}