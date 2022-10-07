#include "menu.h"
#include <memory>
/**
   * Sub menu constructor
     * */
Menu::Menu(std::shared_ptr<Menu> Parent, std::string Name){
    name = Name;
    parent=Parent;
    auto return_item = Parent;
    registerMenuItem(return_item);
}
/**
   * Toplevel menu constructor */
Menu::Menu(std::function<void()> quitCallback,std::string Name){// top level menu
    name = Name;
    auto return_item = std::make_shared<Callback>("Go Back",quitCallback);
    registerMenuItem(return_item);
}
int Menu::getIdx(){
    return idx;
}

const std::vector<std::string>& Menu::getNames(){
    return names;
}

void Menu::registerMenuItem(std::shared_ptr<Item> item){
    items_list.push_back(item);
    names.push_back(item->get_name());
    len++;
}

void Menu::increment(){
    if(idx==len-1){idx = 0;}
    else{idx++;}
};

void Menu::decrement(){
    if(idx==0){idx = len-1;}
    else{idx--;}
};
/**
   *Returns an item of some description w */
std::shared_ptr<Item> Menu::enter(){
    auto Caller = static_cast<std::shared_ptr<Item>>(shared_from_this());
    switch (items_list.at(idx)->get_type()) {
        case Item::MENU:
            return items_list.at(idx);
        case Item::CALLBACK:
            std::dynamic_pointer_cast<Callback>(items_list.at(idx))->cb();
            return Caller;
        case Item::SLIDER:
            return items_list.at(idx);
        default:
            return Caller;
    }
}

Callback::Callback(std::string Name, std::function<void()> Callback){
    name = Name;
    cb = Callback;
}
/*
** returns pointer to itself
   */
std::shared_ptr<Item> Callback::enter(){
    cb();
    return static_cast<std::shared_ptr<Item>>(shared_from_this());
}

