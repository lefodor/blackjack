#include <iostream>
#include <vector>
using namespace std ;

class Card
{
private:
	char suit;
	int value; // value of the card in blackjack
	bool indeck = 1; // 1:card is in the deck, 0:card is at player
public:
	Card(const char s, const int v) : suit(s), value(v) {};

	int getValue() const {
        return value;
	};
};

class CardDeck
{
private:
	std::vector<Card*> cards;
public:
	CardDeck(){
        char suits[4] = { 'c','d','h','s' };
        for (int s = 0; s < 4; s++) {
            for (int v=0; v < 13; v++) {
                int cardvalue = v < 10 ? v : 10;
                Card* CardToAdd = new Card(suits[s], cardvalue);
                cards.push_back(CardToAdd);
            }
        }
	};
	~CardDeck() {};
	int getIthelement(int i) {
        return cards[i]->getValue();
	} ;
};

int main(){

    CardDeck deck1 ;
    cout << deck1.getIthelement(43) << endl;

    int v=3 ;
    int c=2 ;
    v+=c;
    cout << v << endl ;
    cout << c << endl ;

    return 0 ;
}
