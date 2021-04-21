#pragma once
#include <vector>
#include "Card.hpp"
class CardDeck
{
private:
	std::vector<Card> cards;
public:
	CardDeck();
	~CardDeck() {};
	Card& getIthelement(int) ;
};