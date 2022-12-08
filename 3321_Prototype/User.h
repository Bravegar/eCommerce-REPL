#pragma once
#include<string>
#include<vector>

using namespace std;
class User 
{
private:
	string fName, lName, address,
		email, username, password;
	int phone;
	double sellerRating, buyerRating;
	bool banStatus;

public:
	User() 
	{
		fName = "John"; lName = "Doe";
		address = "1234 willow peek";
		username = "TempUsername"; password = "TempPass";
		phone = -1; sellerRating = -1;
		buyerRating = -1; banStatus = false;
	}
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
	double getSellerRating();
	void setSellerRating(double user_input);
	double getBuyerRating();
	void setBuyerRating(double user_input);
	string getUsername();
	void setUsername(string user_input);
	string getPassword();
	void setPassword(string user_input);
	bool getBanStatus();
	void setBanStatus(bool user_input);
};

