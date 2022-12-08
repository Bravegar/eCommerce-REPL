#include <iostream>
#include <string>
#include "Card.h"



Card::Card(std::string sID, int cID, double p, std::string n, std::string t,int numToSell)
{
	setID = sID;
	cardID = cID;
	price = p;
	pokemonName = n;
	type = t;
	cardsBeingSold = numToSell;
}
Card::Card(std::string name, double price)
{
	pokemonName = name;
	this->price = price;
}
void Card::setSetID(std::string id)
{
	setID = id;
}

void Card::setCardID(int id)
{
	cardID = id;
}

void Card::setCardsBeingSold(int num)
{
	cardsBeingSold = num;
}

void Card::setPrice(double p)
{
	price = p;
}

void Card::setPokemonName(std::string n)
{
	pokemonName = n;
}

void Card::setType(std::string t)
{
	type = t;
}
std::string Card::getSetID()
{
	return setID;
}
int Card::getCardID()
{
	return cardID;
}
int Card::getCardsBeingSold()
{
	return cardsBeingSold;
}
double Card::getPrice()
{
	return price;
}
std::string Card::getPokemonName()
{
	return pokemonName;
}
std::string Card::getType()
{
	return type;
}


void Card::display()
{
	std::cout << "Set ID: " << getSetID() << std::endl;
	std::cout << "Card ID: " << getCardID() << std::endl;
	std::cout << "Pokemon: " << getPokemonName() << std::endl;
	std::cout << "Type: " << getType() << std::endl;
	std::cout << "Price: " << getPrice() << std::endl;
	std::cout << "Cards Being Sold: " << getCardsBeingSold() << std::endl;
}
