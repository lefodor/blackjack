#include "Card.hpp"

Card::Card(const char s, const int v) : suit(s), value(v) {};

int Card::getValue() {
	return value;
};