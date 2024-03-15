#include "ui.hpp"
#include <iostream>
#include <stdio.h>

#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

using namespace snake_game;

//------------------------------------------------------------------------

UI* UI::ui;

UI* UI::get(UIMode mode)
{
    if (ui) 
    {
        return ui;
    }

    if (mode == text_mode)
    {
        ui = new TextUI;

        return ui; 
    }

    ui = new GraphicsUI;

    return ui;
};

//------------------------------------------------------------------------

UI::UI() {};
UI::~UI() {};

void UI::draw() {};

//------------------------------------------------------------------------

TextUI::TextUI()
{
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    width = w.ws_col;
    height = w.ws_row;

    termios attributes;
    tcgetattr(STDIN_FILENO, &attributes);

    saved_attributes = attributes;

    attributes.c_lflag &= ~ECHO;
    attributes.c_lflag &= ~ICANON;
    // to prohibit Ctrl C can use ISIG

    tcsetattr(STDIN_FILENO, TCSANOW, &attributes);
    std::cout << 'aaa' << std::endl;
};

TextUI::~TextUI() 
{
    tcsetattr(STDIN_FILENO, TCSANOW, &saved_attributes); //stty sane
    std::cout << 'bbb' << std::endl;
};

void TextUI::draw()
{
    clear_screen();
    set_colour(green_);


    put_line_of_chars('@', '@', '@');
    for (uint8_t cnt = 0; cnt != height - 2; ++cnt)
    {
        put_line_of_chars('@', ' ', '@');
    }
    put_line_of_chars('@', '@', '@');

    set_colour(white_);
};

void TextUI::clear_screen() const
{
    std::cout << "\e[H\e[J" << std::flush;
};

void TextUI::set_colour(Colour colour_) const
{
    std::cout << "\x1b[" << colour_ << "m" << std::flush;
    std::cout << std::flush;
};

void TextUI::move_to_coord() const
{

};

void TextUI::put_line_of_chars(char left_char, char mid_char, char right_char) const
{
    int length = width - 2;

    if (length < 0)
    {
        std::cout << "ERROR::too small teminal" << std::endl;
        return;
    }

    std::cout << left_char;
    for (size_t cnt = 0; cnt != length; ++cnt)
    {
        std::cout << mid_char;
    }
    std::cout << right_char << std::flush;
};

//------------------------------------------------------------------------

GraphicsUI::GraphicsUI() {};
GraphicsUI::~GraphicsUI() {};

void GraphicsUI::draw() {};

//------------------------------------------------------------------------
