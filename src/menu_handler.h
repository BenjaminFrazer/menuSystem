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
        MenuHandler(std::shared_ptr<Item>);
        std::shared_ptr<Item> currentMenu;
        void increment();
        void decrement();
        void enter();
        bool isActive;
    private:
        // void setQuitCb();
};
