EXEC = ShapeMovement 

CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

GARBAGE = */*/*.gch */*.gch
OBJ = main.o functions.o Shape.o Control.o



SHAPE_CPP_FILES 	= Classes/Shape/*.cpp
SHAPE_FILES 	   	= Classes/Shape/*

CONTROL_CPP_FILES	= Classes/Control/*.cpp
CONTROL_FILES 	 	= Classes/Control/*

FUNCTIONS_CPP_FILES 	= Functions/*.cpp
FUNCTIONS_FILES 	= Functions/* 




all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "Compiling.."
	@$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)
	@echo "Delete Garbage.."
	@rm -rf $(OBJ) $(GARBAGE)
	@echo "All is Done"

main.o 		: main.cpp Functions/functions.h
			@echo "Linking main file.."
			@$(CXX) -c main.cpp

functions.o : $(FUNCTIONS_CPP_FILES)
			@echo "Linking Functions.."
			@$(CXX) -c $(FUNCTIONS_FILES)

Shape.o 	: $(SHAPE_CPP_FILES)
			@echo "Linking Shape Class.."
			@$(CXX) -c $(SHAPE_FILES)

Control.o 	: $(CONTROL_CPP_FILES)
			@echo "Linking Control Class.."
			@$(CXX) -c $(CONTROL_FILES)

clean:
	@echo "Cleaning.."
	@rm -rf $(OBJ) $(EXEC) $(GARBAGE)
	@echo "Done #"
