#include "menu.h"

Menu::Menu(std::shared_ptr<Menu> Parent){
    parent=Parent;
    Item return_item{"GoBack",parent};
    registerItem(return_item);
}
Menu::Menu(std::function<void()> quitCallback){// top level menu
    Item return_item{"Quit",parent,true,quitCallback};
    registerItem(return_item);
}
int Menu::getIdx(){
    return idx;
}

bool Menu::getIsCallback(){
    return items.at(idx).isCallback;
}
std::function<void()> Menu::getSelectedCallback(){
    return items.at(idx).callback;
}
void Menu::registerItem(Item item){
    items.push_back(item);
    names.push_back(item.name);
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

std::shared_ptr<Menu> Menu::getSelectedSubMenu(){
    return items.at(idx).child;
}

std::string Menu::getSelectedSubMenuName(){
    return items.at(idx).name;
}
void Menu::print(){
    for(int lp_idx=0; lp_idx<items.size();lp_idx++){
        if(lp_idx==idx){
            std::cout << items.at(lp_idx).name << "<\n";}
        else{
            std::cout << items.at(lp_idx).name << "\n";}
        }
    if(true){
        std::cout << " idx:" << (int)idx << " len:" << (int)len << "\n";
    }
    }

const std::vector<std::string>& Menu::getNames(){
    return names;
}
