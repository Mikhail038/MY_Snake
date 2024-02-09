#include "control.hpp"

std::string Snake::Controller::get_user_line() const
{
    std::string tmp;
    
    std::cin >> tmp;

    return tmp;
}
