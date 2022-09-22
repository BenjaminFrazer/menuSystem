#ifndef UI_H_
#define UI_H_
#include "menu_handler.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <curses.h>
#include <functional>
#include "menu.h"

class UI{
    public:
        UI(std::shared_ptr<MenuHandler> MenuHandler);
        UI();
        void print();
        void regMenuHandler(std::shared_ptr<MenuHandler> MenuHandler);
        void getInput();
        void initCurses();
        void quit();
        void init();
        bool isInit=false;
        std::shared_ptr<MenuHandler> ptrMH;
    private:
        int maxCols;
        int maxLines;
};
#endif // UI_H_
