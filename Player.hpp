#pragma once
#include <vector>
#include "Card.hpp"
class Player
{
private:
	int drawnvalue;
	std::vector<Card*> cardsinhand;
public:
	Player() : drawnvalue(0) {};
	~Player() {};
	void setDrawnValue(int);
	void addCard(Card*);
	int getValueInHand();
	void showHand();
};

