//utils.cpp for battleship
#include <string>
#include <sstream>
#include "utils.hpp"

std::string getLine() {
    std::string result;
    getline(std::cin, result);
    return result;
};

int converterStringToInt(){
    std::stringstream var_s(getLine()) ;
    int var_i ;
    var_s >> var_i ;
    return var_i ;
};

bool checkSize(int p, int s){
    if( p+s>10 ) {
        std::cout << "too big" << std::endl ;
        return false ;
    }
    return true ;
}

bool checkBoardPos(int s, char* chi){
    for(int i=0;i<s;i++){
        if( chi[i] !='.' ){
            std::cout << "not good" << std::endl ;
            return false ;
        }
    }
    return true ;
}

int genValue() {
    int drawn = rand() % 13; 
    switch (drawn) {
    case 1: return 11; break;
    case 10: return 10; break;
    case 11: return 10; break;
    case 12: return 10; break;
    case 13: return 10; break;
    default: return drawn; break;
    }
}