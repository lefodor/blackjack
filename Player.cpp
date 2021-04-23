#include "Player.hpp"

void Player::setDrawnValue(int v) {
	drawnvalue += v;
}

void Player::addCard(Card* newcard) {
	cardsinhand.push_back(newcard);
};

int Player::getValueInHand() {
	int sumValue=0;
	for (auto i : this->cardsinhand) {
		sumValue += i->getValue();
	}
	return sumValue;
};

void Player::showHand() {
	
}