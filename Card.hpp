#pragma once
class Card
{
private:
	char suit;
	int value; // value of the card in blackjack
	bool indeck = 1; // 1:card is in the deck, 0:card is at player
public:
	Card(const char, const int);
	int getValue();
};

