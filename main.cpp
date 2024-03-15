#include "control.hpp"
#include "ui.hpp"
#include <memory>

using namespace snake_game;

int main()
{
    // std::unique_ptr<UI> ui = UI::get(text_mode);

    UI* ui = UI::get(text_mode);
    Game         game(*ui);
    Controller   controller(game);

    ui->draw();

    std::cout << controller.get_user_line() << std::endl;

    delete ui;
}