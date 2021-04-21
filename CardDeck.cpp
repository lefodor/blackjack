#include "CardDeck.hpp"

CardDeck::CardDeck() {
	char suits[4] = { 'c','d','h','s' };
	for (int s = 0; s < 4; s++) {
		for (int v=0; v < 13; v++) {
			cards.push_back(Card(suits[s], v));
		}
	}
}

Card& CardDeck::getIthelement(int i) {
	return cards[i];
}