#include "User.h"
#include<string>
#include<iostream>

using namespace std;

	string User::getFName() 
	{
		return fName;
	}
	void User::setFName(string user_input) {
		fName = user_input;
	}
	string User::getLName() {
		return lName;
	}
	void User::setLName(string user_input) {
		lName = user_input;
	}
	string User::getAddress() {
		return address;
	}
	void User::setAddress(string user_input) {
		address = user_input;
	}
	int User::getPhone() {
		return phone;
	}
	void User::setPhone(int user_input) {
		phone = user_input;
	}
	string User::getEmail() {
		return email;
	}
	void User::setEmail(string user_input) {
		email = user_input;
	}
	double User::getSellerRating() {
		return sellerRating;
	}
	void User::setSellerRating(double user_input) {
		sellerRating = user_input;
	}
	double User::getBuyerRating() {
		return buyerRating;
	}
	void User::setBuyerRating(double user_input) {
		buyerRating = user_input;
	}
	string User::getUsername() {
		return username;
	}
	void User::setUsername(string user_input) {
		username = user_input;
	}
	string User::getPassword() {
		return password;
	}
	void User::setPassword(string user_input) {
		password = user_input;
	}
	bool User::getBanStatus() {
		return banStatus;
	}
	void User::setBanStatus(bool user_input) {
		banStatus = user_input;
	}

