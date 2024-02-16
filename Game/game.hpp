#pragma once

#include "ui.hpp"

namespace Snake
{
    class Game
    {
    private:
        UI& ui_;

    public:
        Game(UI& ui) : ui_(ui) {};
        ~Game() {};
    };
}