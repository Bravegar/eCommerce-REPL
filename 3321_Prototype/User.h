#pragma once
#include<string>
#include<vector>

using namespace std;
class User 
{
	string fName, lName, address,
		email, username, password;
	int phone;
	double sellerRating, buyerRating;
	bool banStatus;
};

string getFName();
void setFName(string user_input);
string getLName();
void setLName(string user_input);
string getAddress();
void setAddress(string user_input);
int getPhone();
void setPhone(int user_input);
string getEmail();
void setEmail(string user_input);
string getSellerRating();
void setSellerRating(double user_input);
string getBuyerRating();
void setBuyerRating(double user_input);
string getUsername();
void setUsername(string user_input);
string getPassword();
void setPassword(string user_input);
bool getBanStatus();
void setBanStatus(bool user_input);
