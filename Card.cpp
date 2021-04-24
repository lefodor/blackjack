#include "Card.hpp"

Card::Card(char s, int v) : suit(s), value(v) { };

int Card::getValue() const {
	return value;
};

char Card::getSuit() const {
	return suit;
};