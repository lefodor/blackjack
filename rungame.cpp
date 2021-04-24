#include "rungame.hpp"
#include "utils.hpp"
#include "Player.hpp"

void title(){
    const int cols = 60 ;
    const int rows = 3 ;
    std::string title = "Blackjack" ;
    std::string author = "program written by: Levente Fodor" ;

    int r2 = (cols-title.size()-2)/2 ;
    int r3 = cols-author.size()-1;

    int r=0,c=0;
    while(r<=rows){
        if(r==0){
            while(c<=cols){
                std::cout << '*' ;
                c++;
            }
            std::cout << std::endl ;
            c=0;
        }
        if(r==1){
            while(c<=r2){
                std::cout << '*' ;
                c++;
            }
            std::cout << ' ' << title << ' ' ;
            c+=title.size()+2;
            while(c<=cols){
                std::cout << '*' ;
                c++;
            }
            std::cout << std::endl ;
            c=0;
        }
        if(r==3){
            std::cout << author << ' ' ;
            c=author.size()+1 ;
            while(c<=cols){
                std::cout << '*' ;
                c++;
            }
            std::cout << std::endl ;
            c=0;
        }
        r++ ;
    }
}

int menu(){
    std::string uinp_s ;
        do{
            title();
            std::cout <<"1. Start game" << std::endl ;
            std::cout <<"2. Quit game" << std::endl ;

            std::stringstream uinp ;
            uinp << getLine() ;

            uinp >> uinp_s;

            if(uinp_s=="2") { 
                std::cout << "Thanks for playing. Goodbye.\n" ; 
                exit(3) ; }
            else if(uinp_s=="1") { 
                std::cout << "Start game\n" ;}
            else { 
                std::cout << "Please choose 1 or 2 then hit Enter.\n" ; } ;
        }while(!(uinp_s=="1" || uinp_s=="2"));
        return EXIT_SUCCESS;
};

int playerChoiceMenu() {
    std::string uinp_s;
    do {
        std::cout << "1. Hit" << std::endl;
        std::cout << "2. Stand" << std::endl;
        std::cout << "3. Quit game" << std::endl;

        std::stringstream uinp;
        uinp << getLine();

        uinp >> uinp_s;

        if (uinp_s == "3") {
            std::cout << "Thanks for playing. Goodbye.\n";
            exit(3);
        }
        else if (uinp_s == "1") {
            return 1;
        }
        else if (uinp_s == "2") {
            return 2;
        }
        else {
            std::cout << "Please choose 1,2 or 3 then hit Enter.\n";
        };
    } while (!(uinp_s == "1" || uinp_s == "2"));
    return EXIT_SUCCESS;
};

int anyBusts(Player& p, Player& d) {
    if (p.chkBust() && d.chkBust()) {
        std::cout << "Dealer and Player got bust!!!" << std::endl;;
        return 1;
    }
    if (p.chkBust() && !d.chkBust()) {
        std::cout << "Player got bust!!! Dealer wins..." << std::endl;;
        return 2;
    }
    if (!p.chkBust() && d.chkBust()) {
        std::cout << "Dealer got bust!!! Player wins..." << std::endl;;
        return 3;
    }
    if (!p.chkBust() && !d.chkBust()) {
        return 0;
    }
    return 0;
}

int anyWon(Player& p, Player& d) {
    if (p.chk21() && d.chk21()) {
        std::cout << "Player and Dealer got 21!!! Draw..." << std::endl;
        return 1;
    }
    if (!p.chk21() && d.chk21()) {
        std::cout << "Dealer got 21!!! Dealer wins..." << std::endl;
        return 2;
    }
    if (p.chk21() && !d.chk21()) {
        std::cout << "Player got 21!!! Player wins..." << std::endl;
        return 3;
    }
    if (!p.chk21() && !d.chk21()) {
        return 0;
    }
    return 0;
}

int rungame(Player& p, Player& d, CardDeck& cd) {
    int round = 0;
    bool endgame = false;
    int playerChoice = 1;
    do {
        // player's turn draw additional card
            // take 2 cards from cardsindeck and put them to cardsnotindeck
            // add the 2 cards to Player's cardsinhand
        int cardsToDrawn = round == 0 ? 2 : 1;
        if (playerChoice == 1) {
            for (int i = 0; i < cardsToDrawn; i++) {
                p.addCard(cd[genValue(cd.indeckSize())]);
            }
        }

        if (d.getValueInHand() < 17) {
            // dealers first two cards
            for (int i = 0; i < cardsToDrawn; i++) {
                d.addCard(cd[genValue(cd.indeckSize())]);
            }
        }

        std::cout << "round #" << round << std::endl;
        // show dealer's hand
        std::cout << "dealer:" << std::endl;
        d.showHand();

        // show player's hand
        std::cout << "player:" << std::endl;
        p.showHand();

        // check if player at 21 
            // --> if yes, player wins
            // --> if above, player busts
            // --> else player game continues
        if (anyWon(p, d) != 0 || anyBusts(p, d) != 0) {
            endgame = true;
        }

        if (!endgame) {
            // increment round
            round++;
            playerChoice=playerChoiceMenu();
        }

    } while (!endgame);

    return 0;
}