#include "control.hpp"

int main()
{
    Snake::UI           ui;
    Snake::Game         game (ui);
    Snake::Controller   controller(game);

    std::cout << controller.get_user_line() << std::endl;
}