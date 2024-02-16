#include "control.hpp"
#include "ui.hpp"

using namespace Snake;

int main()
{
    UI* ui = UI::get(text);
    Game         game(*ui);
    Controller   controller(game);

    ui->draw();

    std::cout << controller.get_user_line() << std::endl;
}