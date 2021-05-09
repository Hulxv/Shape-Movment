#include <iostream>
#include <string>
#include "Shape.hpp" 
#include "../Control/Control.hpp"
#include "../../Functions/functions.h"
using namespace std;

#define WHITEBACK "\033[47m"    // white color for background
#define BLACKFORE "\033[30m"    // black color for foreground
#define DEFAULT "\033[0m"       // default color

void Shape::view(){
    string block = "[]=-+-=[]";
    for (int i = paddingTop+1; i <= block.length() * Height + paddingBottom; i++)
     { 
         for (int j = paddingLeft+1; j <= ( block.length() * Width ) - paddingRight; j+=block.length())
         {
            gotoxy(j,i);                                                         
            cout << block;  
         }       
     }

}


void Shape::printINFOS(int x, int y, int Key){
    gotoxy(x,y);
        cout << WHITEBACK << BLACKFORE << "     INFORMATIONS    "<< DEFAULT;
    gotoxy(x,y+1);                                     
        cout << WHITEBACK << BLACKFORE << " Padding Left: " << this->paddingLeft       << "   "<< DEFAULT;
    gotoxy(x,y+2);
        cout << WHITEBACK << BLACKFORE << " Padding Top : " << this->paddingTop        << "   " << DEFAULT ;
    gotoxy(x,y+3);
        cout << WHITEBACK << BLACKFORE << "                   " << DEFAULT;
    gotoxy(x,y+4);
        cout << WHITEBACK << BLACKFORE << "                   " << DEFAULT;
    gotoxy(x,y+5);
        cout << WHITEBACK << BLACKFORE << " Key        : " << (char)Key             << "   " << DEFAULT;
    gotoxy(x,y+6);
        cout << WHITEBACK << BLACKFORE << " ASCII Code : " << Key                   << "   " << DEFAULT;
    gotoxy(x,y+7);
        cout << WHITEBACK << BLACKFORE << "                   " << DEFAULT;
    gotoxy(x,y+8);
        cout << WHITEBACK << BLACKFORE << "                   " << DEFAULT;
    gotoxy(x,y+9);
        cout << WHITEBACK << BLACKFORE << " Width      : " << Width                 << "   " << DEFAULT;
    gotoxy(x,y+10);
        cout << WHITEBACK << BLACKFORE << " Height     : " << Height                << "   " << DEFAULT;


}
Shape::Shape(){

}
Shape::~Shape(){

}