CXX = g++
CXX_FLAGS = -Wall -Wextra -g -ggdb3

DIR = -IControl -IGame -IUserInterface
CXX_FLAGS += $(DIR)

OBJ = Objects
TRGT = snake
VPATH = $(OBJ):Game:UserInterface:Control

SOURCE = main.cpp Game/game.cpp UserInterface/ui.cpp Control/control.cpp
OBJECTS = $(OBJ)/main.o $(OBJ)/game.o $(OBJ)/ui.o $(OBJ)/control.o

all: FOLDERS $(TRGT)

$(OBJ)/game.o: Game/game.cpp
	$(CXX) -c $< -o $@ $(CXX_FLAGS)

$(OBJ)/ui.o: UserInterface/ui.cpp
	$(CXX) -c $< -o $@ $(CXX_FLAGS)

$(OBJ)/control.o: Control/control.cpp
	$(CXX) -c $< -o $@ $(CXX_FLAGS)

$(OBJ)/main.o: main.cpp
	$(CXX) -c $< -o $@ $(CXX_FLAGS)


$(TRGT): $(OBJECTS) 
	$(CXX) $^ -o $@.bin $(CXX_FLAGS)

FOLDERS:
	@mkdir -p $(OBJ)

clean: 
	@rm -rf $(OBJ)
	@rm -rf $(TRGT)

run: $(TRGT).bin
	@./$<