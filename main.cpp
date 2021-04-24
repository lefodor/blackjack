#include <iostream>
#include <time.h>
#include "empty.hpp"
#include "utils.hpp"
#include "rungame.hpp"
#include "Card.hpp"
#include "CardDeck.hpp"
#include "Player.hpp"
using namespace std ;

int main(){

    /// set random number generator
    srand(time(NULL)); /// initialize only once in application!!!

    CardDeck deck1;
    cout << deck1[2]->getValue() << endl;
    cout << deck1.indeckSize() << endl;
    cout << deck1.notindeckSize() << endl;

    while(true){
        // menu 
        menu() ;
        
        // create players
        Player p1 ;
        Player dealer;
        
        // run game
        int v=rungame(p1,dealer,deck1);

        //cout << p1.getValueInHand() << endl;
        //if( rungame() ){
        //    return 0 ;
        //} ;
    };
    return 0 ;
}