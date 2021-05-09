#ifndef SHAPE_H
#define SHAPE_H

class Shape {


	public:
		
		int paddingTop = 0;
		int paddingBottom = 0;
		int paddingRight = 0;
		int paddingLeft = 0;		
		
		
		int Height = 2;
		int Width = 6;
		
		Shape();
		void view();
		void printINFOS(int x,int y, int Key);
		~Shape();
		

};
#endif