#include "User.h"

User::User(std::string fN, std::string lN, std::string e, std::string a, std::string u, std::string p, int ph)
{
	fName = fN;
	lName = lN;
	email = e;
	address = a;
	username = u;
	password = p;
	phone = ph;
	sellerRating = 0;
	buyerRating = 0;
	banStatus = false;
}

//============ accessor functions
std::string User::getFName()
{
	return fName;
}

std::string User::getLName()
{
	return lName;
}

std::string User::getEmail()
{
	return email;
}

std::string User::getAddress()
{
	return address;
}

std::string User::getUsername()
{
	return username;
}

std::string User::getPassword()
{
	return password;
}

int User::getPhone()
{
	return phone;
}

bool User::getBanStatus()
{
	return banStatus;
}

double User::getSellerRating()
{
	return sellerRating;
}

double User::getBuyerRating()
{
	return buyerRating;
}

//============ mutator functions
void User::setFName(std::string user_input)
{
	fName = user_input;
}

void User::setLName(std::string user_input)
{
	lName = user_input;
}

void User::setAddress(std::string user_input)
{
	address = user_input;
}

void User::setPhone(int user_input)
{
	phone = user_input;
}

void User::setEmail(std::string user_input)
{
	email = user_input;
}

void User::setSellerRating(double user_input)
{
	sellerRating = user_input;
}

void User::setBuyerRating(double user_input)
{
	buyerRating = user_input;
}

void User::setUsername(std::string user_input)
{
	username = user_input;
}

void User::setPassword(std::string user_input)
{
	password = user_input;
}

void User::setBanStatus(bool user_input)
{
	banStatus = user_input;
}

void User::display()
{
	std::cout << "User Information\n";
	std::cout << "First Name: " << getFName();
	std::cout << "Last Name: " << getLName();
	std::cout << "Username: " << getUsername();
	std::cout << "Email: " << getEmail();
	std::cout << "Address: " << getAddress();
	std::cout << "Phone Number: " << getPhone();
	std::cout << "Seller Rating: " << getSellerRating();
	std::cout << "Buyer Rating: " << getBuyerRating();
}
