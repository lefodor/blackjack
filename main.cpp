#include <iostream>
#include <time.h>
#include "empty.hpp"
#include "utils.hpp"
#include "rungame.hpp"
using namespace std ;

int main(){

    /// set random number generator
    srand(time(NULL)); /// initialize only once in application!!!

    while(true){
        // menu m
        menu() ;
        
        // create players
        //Player p1 ;
        //Player p2(p1) ;
        //Player p2 ;
        
        // run game, 17=5+4+3+3+2 (sizes of all ships)
        //if( rungame(p1, p2, 17)==1 ){
        //    return 0 ;
        } ;
    //};
    return 0 ;
}