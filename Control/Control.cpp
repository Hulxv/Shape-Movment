#include "Control.hpp"
#include <iostream>
#include "../Person/Person.hpp"
#include "../Functions/functions.h"
using namespace std;
#ifdef _WIN32 
    #define OS "WIN" // Windows
#elif defined(_WIN64)
    #define OS "WIN"
#elif defined(UNIX)
    #define OS "UNIX"
#elif defined(__linux__)
    #define OS "linux"
#else
    cout << "NOT Supported"<< endl;
    return -1;
#endif
Control::Control(Person OBJ)
{
    while (true)
    {
        OBJ.view(OBJ);
        Key = getch();
        gotoxy(5, 57);
        cout << "Key: " << Key << "\t"
             << "Code: " << (char)Key;
        if(OS == "WIN")                         system("cls");
        else if(OS == "UNIX" || "LINUX")  system("clear");

        if (Key == Left)
        {
            if (OBJ.paddingLeft > 0)
            {
                OBJ.paddingRight--;
                OBJ.paddingLeft++;
            }
        }
        else if (Key == Right && OBJ.paddingRight > Width)
        {
            OBJ.paddingLeft++;
            OBJ.paddingRight--;
        }
        else if (Key == Top)
        {
            if (OBJ.paddingBottom > 0 && OBJ.paddingTop > 0)
            {
                OBJ.paddingBottom--;
                OBJ.paddingTop--;
            }
        }
        else if (Key == Back && OBJ.paddingBottom < Height)
        {

            OBJ.paddingTop++;
            OBJ.paddingBottom++;
        }
        else if (Key == 'x' && OBJ.paddingBottom < Height && OBJ.paddingRight > Width )
        {

            OBJ.paddingTop++;
            OBJ.paddingLeft++;
            OBJ.paddingRight--;
            OBJ.paddingBottom++;
        }
        else if (Key == 'a')
        {
            if (OBJ.paddingTop && OBJ.paddingLeft > 0)
            {
                OBJ.paddingTop--;
                OBJ.paddingLeft--;
                OBJ.paddingRight++;
                OBJ.paddingBottom--;
            }
        }
        else if (Key == 's')
        {
            if (OBJ.paddingTop > 0 && OBJ.paddingRight > Width)
            {
                OBJ.paddingTop--;
                OBJ.paddingLeft++;
                OBJ.paddingRight--;
                OBJ.paddingBottom--;
            }
        }
        else if (Key == 'z')
        {
            if (OBJ.paddingLeft > 0 && OBJ.paddingBottom < Height)
            {
                OBJ.paddingTop++;
                OBJ.paddingLeft--;
                OBJ.paddingRight++;
                OBJ.paddingBottom++;
            }
        }

        if (Key == Enter){
            break;
        }
            
        if (Key == Reset)
        {
            OBJ.paddingTop = 0;
            OBJ.paddingBottom = 0;
            OBJ.paddingRight = 0;
            OBJ.paddingLeft = 0;
        }
    }
}



/*
TODO List :

* بتزود طول المربع
if (OBJ.paddingBottom > 0 && OBJ.paddingTop > 0)
            {
                OBJ.paddingBottom++;
                OBJ.paddingTop--;
            }


* بتقلل طول المربع
if (Key == "Button" && OBJ.paddingBottom < Height)
        {

            OBJ.paddingTop++;
            OBJ.paddingBottom--;
        }
*/