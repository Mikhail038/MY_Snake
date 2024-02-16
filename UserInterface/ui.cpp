#include "ui.hpp"
#include <iostream>
#include <stdio.h>

using namespace Snake;

//------------------------------------------------------------------------

UI* UI::ui;

UI* UI::get(UIMode mode)
{
    if (ui) 
    {
        return ui;
    }

    if (mode == text)
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

TextUI::TextUI() {};
TextUI::~TextUI() {};

void TextUI::draw()
{
    // clear_screen();

    set_colour(white_);

    put_line_of_chars('<', '=', '>');
    put_line_of_chars();
    put_line_of_chars();

    set_colour(blue_);

    put_line_of_chars('<', '=', '>');
    put_line_of_chars('<', '=', '>');
    put_line_of_chars('<', '=', '>');


    set_colour(red_);

    put_line_of_chars();
    put_line_of_chars();
    put_line_of_chars('<', '=', '>');
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
    winsize window;
    ioctl(0, TIOCGWINSZ, &window);

    int length = window.ws_col - 2;

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
