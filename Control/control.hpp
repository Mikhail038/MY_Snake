#pragma once
#include <string>
#include <iostream>

#include "game.hpp"

namespace Snake
{
    class Controller
    {
        private:
        Game& game_;
        
        public:
        Controller(Game& game): game_(game)
        {

        }
        std::string get_user_line() const;
    };
}