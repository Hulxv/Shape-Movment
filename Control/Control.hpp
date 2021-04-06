#ifndef CONTROL_H
#define CONTROL_H
#include "../Person/Person.hpp"
class Control  
{
int Key;
enum DIM {
		Height = 65,
		Width  = -125
	};
	public:
		const int Top	   	= 65;
		const int Back     	= 66;
		const int Right    	= 67;
		const int Left 		= 68;
		const int Enter 	= 10;
		const int ZoomIn 	= 122;
		const int ZoomOut	= 120;
		const int Reset 	= 114;
		
		
		Control(Person OBJ);

};
#endif