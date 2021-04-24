#include <iostream>
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
	int i = 0;
	std::cout 
		<< "\t" << "value in hand: "
		<< getValueInHand() << std::endl;
	for (auto c : cardsinhand) {
		i++;
		std::cout 
			<< "\t" << "card#" << i << " "
			<< c->getSuit() << c->getValue()
			<< std::endl;
	}
}

bool Player::chkBust() {
	return getValueInHand() > 21 ? true : false;
}