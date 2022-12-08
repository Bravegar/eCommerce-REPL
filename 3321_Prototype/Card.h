#pragma once
#include <string>
class Card
{


	std::string setID;
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
	Card(std::string, int, double, std::string, std::string, int);
	Card(std::string, double );
	//============ accessor functions
	std::string getSetID();
	int getCardID();
	int getCardsBeingSold();
	double getPrice();
	std::string getPokemonName();
	std::string getType();
	//============ mutator functions
	void setSetID(std::string);
	void setCardID(int);
	void setCardsBeingSold(int);
	void setPrice(double);
	void setPokemonName(std::string);
	void setType(std::string);
	//============ display functions
	void display();
};
