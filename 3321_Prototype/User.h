#pragma once
#include<iostream>
#include<string>
#include<vector>


class User 
{
private:
	std::string fName, lName, address,
		email, username, password;
	std::string phone;
	double sellerRating, buyerRating;
	bool banStatus;
public:
	//============ constructors
	User()
	{
		fName = "";
		lName = "";
		email = "";
		address = "";
		username = "";
		password = "";
		phone = "";
		sellerRating = -1;
		buyerRating = -1;
		banStatus = false;
	}
	User(std::string, std::string, std::string, std::string, std::string, std::string, std::string);
	//============ accessor functions
	std::string getFName();
	std::string getLName();
	std::string getEmail();
	std::string getAddress();
	std::string getUsername();
	std::string getPassword();
	std::string getPhone();
	double getSellerRating();
	double getBuyerRating();
	bool getBanStatus();
	//============ mutator functions
	void setFName(std::string user_input);
	void setLName(std::string user_input);
	void setAddress(std::string user_input);
	void setPhone(std::string user_input);
	void setEmail(std::string user_input);
	void setSellerRating(double user_input);
	void setBuyerRating(double user_input);
	void setUsername(std::string user_input);
	void setPassword(std::string user_input);
	void setBanStatus(bool user_input);
	//=========== display
	void display();
};

