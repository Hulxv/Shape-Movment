// #include <iomanip.h>
#include <iostream>
#include "Control.hpp"

#include "../../Functions/functions.h"
using namespace std;


//Check from Operation System
#ifdef _WIN32 
    #define OS "WIN"        // Windows 32bit
#elif defined(_WIN64)
    #define OS "WIN"
#elif defined(UNIX)
    #define OS "UNIX"       // UNIX family system

#elif defined(__linux__)
    #define OS "linux"      // LINUX family system

#else
    cout << "NOT Supported"<< endl; // if another operation system 
    return -1;
#endif


#define WHITEBACK "\033[47m"    // white color for background
#define BLACKFORE "\033[30m"    // black color for foreground
#define REDFORE   "\033[31m"    // red color for foreGround
#define DEFAULT   "\033[0m"     // default color

Control::Control()
{
   // Empty
}
void Control::Refresh(Shape OBJ){
     while (true)
    {
        
            printCTRLS(18, 63);
        OBJ.printINFOS(0 , 63, Key);
        OBJ.view();
       
        Key = getch();
        
        if(getKEY(OBJ, Key) == -1){
            if     (OS == "WIN")              system("cls");
            else if(OS == "UNIX" || "LINUX")  system("clear");
            break;
        }
        else{
            getKEY(OBJ,Key);
        }
        
        if     (OS == "WIN")              system("cls");
        else if(OS == "UNIX" || "LINUX")  system("clear");
        
        
    }
}
int Control::getKEY(Shape &OBJ, int Key){
        if (Key == Left) // TO MOVE THE SHAPE TO LEFT
        {
            if (OBJ.paddingLeft > 0)
            {
                OBJ.paddingRight++;
                OBJ.paddingLeft--;
            }
        }
        else if (Key == Right && OBJ.paddingRight > Width) // TO MOVE THE SHAPE TO RIGHT
        {
            OBJ.paddingLeft++;
            OBJ.paddingRight--;
        }
        else if (Key == UP) // TO MOVE THE SHAPE TO UP
        {
            if (OBJ.paddingBottom > 0 && OBJ.paddingTop > 0)
            {
                OBJ.paddingBottom--;
                OBJ.paddingTop--;
            }
        }
        else if (Key == Down && OBJ.paddingBottom < Height) // TO MOVE THE SHAPE TO DOWN
        {

            OBJ.paddingTop++;
            OBJ.paddingBottom++;
        }

        else if (
                       Key == rightDown 
                    && OBJ.paddingBottom < Height 
                    && OBJ.paddingRight  > Width 
                ) // IF USER WANT MOVE TO RIGHT-DOWN
        {

            OBJ.paddingTop++;
            OBJ.paddingLeft++;
            OBJ.paddingRight--;
            OBJ.paddingBottom++;
        }

        else if (Key == leftUp) // IF USER WANT MOVE THE SHAPE TO LEFT-UP
        {
            if (OBJ.paddingTop && OBJ.paddingLeft > 0)
            {
                OBJ.paddingTop--;
                OBJ.paddingLeft--;
                OBJ.paddingRight++;
                OBJ.paddingBottom--;
            }
        }

        else if (Key == rightUp) // IF USER WANT MOVE THE SHAPE TO RIGHT-UP
        {
            if (OBJ.paddingTop > 0 && OBJ.paddingRight > Width)
            {
                OBJ.paddingTop--;
                OBJ.paddingLeft++;
                OBJ.paddingRight--;
                OBJ.paddingBottom--;
            }
        }
        
        else if (Key == leftDown) // IF USER WANT MOVE THE SHAPE TO LEFT-DOWN
        {
            if (OBJ.paddingLeft > 0 && OBJ.paddingBottom < Height)
            {
                OBJ.paddingTop++;
                OBJ.paddingLeft--;
                OBJ.paddingRight++;
                OBJ.paddingBottom++;
            }
        }

        else if (Key == Enter) // TO END GAME
        { 
            return -1;
        }
            
        else if (Key == Reset) // TO RESET GAME
        {
            OBJ.paddingTop = 0;
            OBJ.paddingBottom = 0;
            OBJ.paddingRight = 0;
            OBJ.paddingLeft = 0;
        }

        return 0;
}
void Control::printCTRLS(int x, int y) {
        gotoxy(x,y);
            cout << WHITEBACK << BLACKFORE <<"           CONTROLS        ";
        gotoxy(x,y+1);
            cout << WHITEBACK << BLACKFORE <<"    UP         : ( " << (char)UP         << " )     " << DEFAULT;
        gotoxy(x,y+2);
            cout << WHITEBACK << BLACKFORE <<"    DOWN       : ( " << (char)Down       << " )     " << DEFAULT;
        gotoxy(x,y+3);
            cout << WHITEBACK << BLACKFORE <<"    LEFT       : ( " << (char)Left       << " )     " << DEFAULT;
        gotoxy(x,y+4);
            cout << WHITEBACK << BLACKFORE <<"    RIGHT      : ( " << (char)Right      << " )     " << DEFAULT;
        gotoxy(x,y+5);
            cout << WHITEBACK << BLACKFORE <<"    LEFT-UP    : ( " << (char)leftUp     << " )     " << DEFAULT;
        gotoxy(x,y+6); 
            cout << WHITEBACK << BLACKFORE <<"    LEFT-DOWN  : ( " << (char)leftDown   << " )     " << DEFAULT;
        gotoxy(x,y+7);
            cout << WHITEBACK << BLACKFORE <<"    RIGHT-UP   : ( " << (char)rightUp    << " )     " << DEFAULT;
        gotoxy(x,y+8);
            cout << WHITEBACK << BLACKFORE <<"    RIGHT-DOWN : ( " << (char)rightDown  << " )     " << DEFAULT;
        gotoxy(x,y+9);
            cout << WHITEBACK << BLACKFORE <<"    RESET      : ( " << (char)Reset      << " )     " << DEFAULT;
        gotoxy(x,y+10);
            cout << WHITEBACK << REDFORE   <<"    QUIT       : ( " << "ENTER"          << " ) "     << DEFAULT;
}

Control::~Control(){
    cout << "END\n";
}
