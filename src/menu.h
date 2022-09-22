#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <curses.h>
#include <functional>

class Menu;

struct Item{
    std::string name;
    std::shared_ptr<Menu> child;
    bool isCallback=false;
    std::function<void()> callback;
};

class Menu{
    public:
        Menu(std::shared_ptr<Menu> parent);
        Menu(std::function<void(void)> quitCallback);
        void registerItem(Item item);
        void increment();
        void decrement();
        std::shared_ptr<Menu> getSelectedSubMenu();
        std::string getSelectedSubMenuName();
        std::function<void()> getSelectedCallback();
        bool getIsCallback();
        void print();
        const std::vector<std::string>& getNames();
        int getIdx();
    private:
        std::vector<Item> items;
        std::vector<std::string> names;
        uint8_t idx=0;
        uint8_t len=0;
        std::shared_ptr<Menu> parent;
};
