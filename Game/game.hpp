#pragma once

#include "ui.hpp"

#include <stdint.h>

namespace snake_game
{
    class Game
    {
    private:
        UI& ui_;

    public:
        Game(UI& ui) : ui_(ui) {};
        ~Game() {};
    };

    class Snake
    {
        
    }; 

    class Rabbit
    {

    }; 

    class Coordinate
    {
    public:
        uint16_t x;
        uint16_t y;

    private:
        Coordinate(uint16_t x_, uint16_t y);
        ~Coordinate() = default; 
    };
}