#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <curses.h>
#include <functional>
#include "menu.h"

class MenuHandler{
    public:
        MenuHandler(std::shared_ptr<Menu>);
        std::shared_ptr<Menu> currentMenu;
        void increment();
        void decrement();
        void enter();
        void print();
        bool isActive;
    private:
        // void setQuitCb();
};
