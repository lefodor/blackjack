#ifndef RUNGAME_H
#define RUNGAME_H
#include <iostream>
#include "Player.hpp"
#include "CardDeck.hpp"

void title();
int menu() ;
int rungame(Player&, Player&, CardDeck&);
int anyBusts(Player&, Player&);


#endif //RUNGAME_H