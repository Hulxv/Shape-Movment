#include <iostream>
#include <string>
#include "Person.hpp" 
#include "../Functions/functions.h"
using namespace std;


void Person::view(Person OBJ){
    string block = "[]=-+-=[]";
    for (int i = OBJ.paddingTop+1; i <= block.length()*2+OBJ.paddingBottom; i++)
     { 
         for (int j = OBJ.paddingLeft+1; j <= (block.length()*5)-OBJ.paddingRight; j+=block.length())
         {
            gotoxy(j,i);
            // int k;
            // if      (j == OBJ.paddingLeft && OBJ.paddingLeft >= 0)   k = OBJ.paddingLeft;
            // else if (j == OBJ.paddingLeft && OBJ.paddingLeft < 0)    k = (OBJ.paddingLeft) * (-1);
            // else                                                     k = 0;
            for(int k = 0; k < block.length();k++){               
                cout << block[k];
            }
            
            
                
         }       
     }
     gotoxy(5,55);cout << "----------------------------";
     gotoxy(5,59);
     cout << "Left: " << OBJ.paddingLeft << "\t"
        << "Right: " << OBJ.paddingRight; 
    gotoxy(5,61);
     cout << "Top: " << OBJ.paddingTop << "\t"
        << "Bottom: " << OBJ.paddingBottom;
    gotoxy(5,63);cout << "----------------------------";
}