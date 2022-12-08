#include "Sales.h"
#include <iostream>

using namespace std;

int Sales::getSaleNumber()
{
	return saleNumber;
}

void Sales::setSaleNumber(int user_input)
{
	saleNumber = user_input;
}

int Sales::getCustomerID()
{
	return customerID;
}

void Sales::setCustomerID(int user_input)
{
	customerID = user_input;
}

int Sales::getSellerID()
{
	return sellerID;
}

void Sales::setSellerID(int user_input) {
	sellerID = user_input;
}

void Sales::printAll()
{
	/*Display << “Sale Information : ” << “\n”;
	Display << “Sale Number : ” << SalesClass.saleNumber << “\n”;
	Display << “Customer ID : ” << SalesClass.customerID << “\n”;
	Display << “Seller ID : ” << SalesClass.sellerfID << “\n”;*/
	cout << "Sale information: \n"
		<< "Sale number - " << getSaleNumber() << endl
		<< "Customer ID - " << getCustomerID() << endl
		<< "Seller ID - " << getSellerID() << endl;
}	
