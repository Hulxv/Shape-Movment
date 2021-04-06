#ifndef PERSON_H
#define PERSON_H
	
class Person  
{


	public:
		
		int paddingTop = 0;
		int paddingBottom = 0;
		int paddingRight = 0;
		int paddingLeft = 0;		
		void view(Person OBJ);
		enum ShapeDim{
			Height = 6,
			Width = 6
		};

};
#endif