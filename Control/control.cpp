#include "control.hpp"

std::string snake_game::Controller::get_user_line() const
{
    std::string tmp;
    
    std::cin >> tmp;

    return tmp;
}
