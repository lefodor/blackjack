#pragma once
class Card
{
private:
	char suit;
	int value; // value of the card in blackjack
public:
	Card(char, int);
	int getValue() const;
};