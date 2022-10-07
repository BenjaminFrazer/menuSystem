#ifndef UI_H_
#define UI_H_
#include "item.h"
#include "menu_handler.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <curses.h>
#include <functional>
#include "menu.h"

class Box{
    public:
        Box(int x,int y,int width,int height);
        Box(){};
        int height;
        int width;
        int origin_x; /// top left corner
        int origin_y; /// top left corner
        WINDOW *window;
        void draw();
        void print_ln( std::string, int row);
        void highlight_row(int row);
};

class UI{
    public:
        UI(std::shared_ptr<MenuHandler> MenuHandler);
        UI();
        void print();
        void regMenuHandler(std::shared_ptr<MenuHandler> MenuHandler);
        void getInput();
        void initCurses();
        void quit();
        void terminate();
        void init();
        bool isInit=false;
        std::shared_ptr<MenuHandler> ptrMH;
        Box menu_box;
    private:
        bool menuActive = false;
        int maxCols;
        int maxLines;
        void display_menu(std::shared_ptr<Item>);
        void display_slider(std::shared_ptr<Item>);
};
#endif // UI_H_
