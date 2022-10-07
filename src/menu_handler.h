#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <curses.h>
#include <functional>
#include "item.h"
#include "menu.h"

class MenuHandler{
    public:
        MenuHandler(std::shared_ptr<Item>);
        std::shared_ptr<Item> currentItem;
        void increment();
        void decrement();
        void enter();
        bool isActive;
        void reset(); /// revert to the main menu
    private:
        std::shared_ptr<Item> MainMenu;
        // void setQuitCb();
};
