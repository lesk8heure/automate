#! /bin/bash

CXXFLAGS = `wx-config --cxxflags`
EXEC = ACS
INCLUDES = -include wx/wx.h
LIBS = `wx-config --libs`
SRC = $(wildcard src/*.cpp)
OBJ = $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))

all: $(EXEC)

clean:
	rm $(EXEC) $(OBJ);

$(EXEC): $(OBJ) 
	g++ -o $(EXEC) $(OBJ) $(LIBS)

obj/%.o: src/%.cpp
	g++ $(CXXFLAGS) $(INCLUDES) -o $@ -c $<
