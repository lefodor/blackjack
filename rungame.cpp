#include "rungame.hpp"
#include "utils.hpp"

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

int rungame() {

    return 0;
}