#include <iostream>
#include <string>
#include "Functions/functions.h"
#include "Control/Control.hpp"
#include "Person/Person.hpp"

using namespace std;

int main()
{
    system("clear");
    gotoxy(20,20);
    cout << "Press Enter Key to Exit... \n";
    gotoxy(20,21);
    cout << "Press Any Key to Enter The Game";
    int key = getch();
    if(key == 10) return 0;
    else {
        Person Obj;
        Control view(Obj);
    }

    return 0;
}