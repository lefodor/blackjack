#include "CardDeck.hpp"

CardDeck::CardDeck() {
	char suits[4] = { 'c','d','h','s' };
	for (int s = 0; s < 4; s++) {
		for (int v=1; v < 14; v++) {
			int cardvalue = v < 10 ? v : 10;
			if (cardvalue == 1) {
				cardvalue = 11;
			}
			Card* CardToAdd = new Card(suits[s], cardvalue);
			cardsindeck.push_back(CardToAdd);
		}
	}
}

Card& CardDeck::getIthelement(int i) {
	return *(cardsindeck[i]);
}

/*
Card& CardDeck::operator[](int i) {
	return *(cardsindeck[i]);
}
*/

Card* CardDeck::operator[](int i) {
	return (cardsindeck[i]);
}

int CardDeck::indeckSize() {
	return cardsindeck.size();
}

int CardDeck::notindeckSize() {
	return cardsnotindeck.size();
}