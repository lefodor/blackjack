#pragma once
#include <vector>
#include "Card.hpp"
class CardDeck
{
private:
	std::vector<Card*> cardsindeck;
	std::vector<Card*> cardsnotindeck;
public:
	CardDeck();
	~CardDeck() {};
	
	Card& getIthelement(int) ;
	//Card& operator[](int);
	Card* operator[](int);
	Card& drawCard() {

	}

	int indeckSize();
	int notindeckSize();

};