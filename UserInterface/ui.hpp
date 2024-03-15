#pragma once

#include <sys/ioctl.h>
#include <string>
#include <termios.h>
#include <stdint.h>

namespace snake_game
{
//\x1b[%m
    enum Colour
    {
        black_      =   30,
        red_        =   31,
        green_      =   32,
        blue_       =   34,
        yellow_     =   33,
        magenta_    =   35,
        cyan_       =   36,
        white_      =   37,
        normal      =   0,
        bright      =   1,
        dim         =   2,
        underscore  =   4,
        blink       =   5,
        reverse     =   7,
        hidden      =   8,
        black       =   40,
        red         =   41,
        green       =   42,
        yellow      =   43,
        blue        =   44,
        magenta     =   45,
        cyan        =   46,
        white       =   47
    };

    enum UIMode
    {
        text_mode,
        graphics_mode
    };

    class UI
    {
    private:
        std::string game_name = "SNAKA";
    public:
        static UI* ui;

    public:
        UI();// = delete;
        virtual ~UI();

        virtual void draw() = 0;

        static UI* get(UIMode mode = text_mode);

    private:

    };

    class TextUI : public UI
    {
    private:
        uint16_t width;
        uint16_t height;
    
        termios saved_attributes;

    public:
        TextUI();
        virtual ~TextUI();

        virtual void draw();

    private:
        void clear_screen() const;
        void set_colour(Colour colour_) const;

        void move_to_coord() const;

        void put_line_of_chars(char left_char = '<', char mid_char = ' ', char right_char = '>') const;
    };

    class GraphicsUI : public UI
    {
    public:
        GraphicsUI();
        virtual ~GraphicsUI();
 
        virtual void draw();
    };
}

