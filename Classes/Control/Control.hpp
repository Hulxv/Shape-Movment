#ifndef CONTROL_H
#define CONTROL_H
#include "../Shape/Shape.hpp"

class Control {

enum DIM {
		Height = 55,
		Width  = -165
	};
	public:
		      int Key    	= 0  ; // Deafult 
		const int UP	   	= 'w';
		const int Down     	= 's';
		const int Right    	= 'd';
		const int Left 		= 'a';
		const int leftUp    = 'r';
		const int leftDown  = 'f';
		const int rightUp   = 't';
		const int rightDown = 'g'; 

		const int Enter 	= 10 ;  // To quit from app
		const int Reset 	= 'R'; // To reset distance
		
		
		Control();
		int  getKEY (Shape &OBJ, int Key);
		void Refresh(Shape OBJ);
		void printCTRLS(int x, int y);
		~Control();

};
#endif
