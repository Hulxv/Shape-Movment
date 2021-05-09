#include <iostream>
#include <string>
#include "Functions/functions.h"
#include "Classes/Control/Control.hpp"
#include "Classes/Shape/Shape.hpp"

using namespace std;

int main()
{

cout << "\e[8;93;252t";

    system("clear");
    gotoxy(1,10);
    cout << "Press Enter Key to Exit...     ";
    gotoxy(2,11);
    cout << "Press Any Key to Enter The Game";
    int key = getch();
    if(key == 10) return 0;
    else {
        Shape Obj;
        Control view;
        view.Refresh(Obj);
    }

    return 0;
}
