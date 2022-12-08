#pragma once
#include <iostream>

using namespace std;

class Sales 
{
private:

	int saleNumber, customerID, sellerID;
public: 
	Sales()
	{
		saleNumber = 0;
		customerID = 0;
		sellerID = 0;
	}
	int getSaleNumber();
	void setSaleNumber(int user_input);
	int getCustomerID();
	void setCustomerID(int user_input);
	int getSellerID();
	void setSellerID(int user_input);
	void printAll();
};
