#include "menu_handler.h"
MenuHandler::MenuHandler(std::shared_ptr<Item> topLevel){
    currentItem = topLevel;
    MainMenu = topLevel;
}
void MenuHandler::increment(){currentItem->increment();isActive=true;}
void MenuHandler::decrement(){currentItem->decrement();isActive=true;}
void MenuHandler::enter(){
    currentItem = currentItem->enter();
}
void MenuHandler::reset(){
    currentItem = MainMenu;
}
