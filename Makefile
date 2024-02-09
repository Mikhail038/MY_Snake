CXX = g++
CXX_FLAGS = -Wall -Wextra -g -ggdb3

DIR = -IControl -IGame -IUserInterface
CXX_FLAGS += $(DIR)

OBJ = Objects
TRGT = snake.bin
VPATH = $(OBJ):Game:UserInterface:Control

SOURCE = main.cpp Game/game.cpp UserInterface/ui.cpp Control/control.cpp
OBJECTS = main.o game.o ui.o control.o

all: FOLDERS $(OBJECTS) $(TRGT).make

$(TRGT): $(OBJECTS) 
	$(CXX) $^ -o $@ $(CXX_FLAGS)

$(TRGT).make:
	$(MAKE) $(TRGT)

.cpp.o:
	$(CXX) -c $< -o $(OBJ)/$@ $(CXX_FLAGS)

FOLDERS:
	@mkdir -p $(OBJ)

clean: 
	@rm -rf $(OBJ)
	@rm -rf $(TRGT)