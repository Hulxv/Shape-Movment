CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

GARBAGE = */*.gch
OBJ = functions.o main.o Person.o Control.o
EXEC = ShapeMovement
PERSONCPP = Person/*
CONTROLCPP = Control/*
FUNCPP = Functions/*
PERSON = Person/*.cpp
CONTROL = Control/*.cpp
FUNC = Functions/*.cpp
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)
	rm -rf $(OBJ) $(GARBAGE)

main.o : main.cpp Functions/functions.h
	$(CXX) -c main.cpp
functions.o : $(FUNC)
		$(CXX) -c $(FUNCPP)
Person.o : $(PERSON)
		$(CXX) -c $(PERSONCPP)
Control.o : $(CONTROL)
		$(CXX) -c $(CONTROLCPP)
clean:
	rm -rf $(OBJ) $(EXEC) $(GARBAGE)



