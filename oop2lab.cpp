// Пункт 15 // Пункт 13

#include <iostream>
#include <fstream>
#include "HAIRDRESSER.h"

using namespace std;

int main()
{
	customer client1, client2, client3, client4, client5; // Пункт 6 // Пункт 13
	
	// Пункт 6 // Пункт 13

	customer* dynamicClient1 = new customer(); 
	customer* dynamicClient2 = new customer();
	customer* dynamicClient3 = new customer();
	customer* dynamicClient4 = new customer();
	customer* dynamicClient5 = new customer();

	int hairProductsPrices[10] = { 15, 25, 35, 45, 55, 65, 75, 85, 95, 105 }; // Пункт 7 // Пункт 13
	string hairProductsNames[10] = { "Shampoo", "Conditioner", "Hair Gel", "Hair Spray", "Hair Wax", "Hair Mousse", "Leave-in Conditioner", "Hair Serum", "Heat Protectant", "Hair Oil" }; // Пункт 7

	for (int i = 0; i < 10; i++) { 
		cout << "Product: " << hairProductsNames[i] << ", Price: " << hairProductsPrices[i] << endl; // Пункт 8	 // Пункт 13
	}
	
	int productNum = 0;
	cin >> productNum;

	// Пункт 9 -> // Пункт 13

	hairDresser hd1; 
	hd1.creatingHD("HD001", 5, 50, true, "Alice", 1);
	client1.creatingCustomer("Bob", 1234567890, 1001, "C001", true, false);
	client2.creatingCustomer("Bob", 1234567890, 1001, "C001", true, false);

	customer* pclient = &client1;

	client1.merge(client2);

	client1.eldereligible(65);
	pclient->updatePhonenumber(880055535); // Пункт 11 // Пункт 13

	client1.referalLink("Charlie", "C002", 9876543210);

	hd1.printSchedule();

	// Пункт 10 -> // Пункт 13
	hd1.assignClient(client1);
	cout << "Hairdresser " << hd1.name << " is assigned to client with ID: " << client1.id << endl;
	
	hd1.experience(4);
	cout << "Hairdresser " << hd1.name << " has " << hd1.experience() << " years of experience" << endl;
	// <- Пункт 10 // Пункт 13

	if (productNum > 0 && productNum < 11) {
		hd1.calculateCost(2, hairProductsPrices[productNum - 1]);
		client1.addSpent(hd1.calculateCost(2, hairProductsPrices[productNum - 1]), client1.elder);
	}
	else {
		hd1.calculateCost(2);
		client1.addSpent(hd1.calculateCost(2), client1.elder);
	}

	hd1.loadInFile();
	client1.loadInFile();

	customer finishedClient = hd1.finalTouches(client1);
	cout << "Client with ID: " << finishedClient.id << " has completed their appointment." << endl;

	client1.randomPurchases(); // Пункт 12 // Пункт 13

	// <- Пункт 9 // Пункт 13

	delete dynamicClient1;
	delete dynamicClient2;
	delete dynamicClient3;
	delete dynamicClient4;
	delete dynamicClient5;
}