#pragma once
#include <string>
class Card
{


	int setID;
	int cardID;
	int cardsBeingSold;
	double price;
	std::string pokemonName;
	std::string type;

public:
	//============ default constructor
	Card()
	{
		setID = -1;
		cardID = -1;
		cardsBeingSold = 0;
		price = 0.0;
		pokemonName = "";
		type = "";
	}
	Card(int, int, double, std::string, std::string);
	//============ accessor functions
	int getSetID();
	int getCardID();
	int getCardsBeingSold();
	double getPrice();
	std::string getPokemonName();
	std::string getType();
	//============ mutator functions
	void setSetID(int);
	void setCardID(int);
	void setCardsBeingSold(int);
	void setPrice(double);
	void setPokemonName(std::string);
	void setType(std::string);
	//============ display functions
	void display();
};
