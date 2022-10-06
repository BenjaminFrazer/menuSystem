#include "menu_handler.h"
MenuHandler::MenuHandler(std::shared_ptr<Item> topLevel){
    currentMenu = topLevel;
}
void MenuHandler::increment(){currentMenu->increment();isActive=true;}
void MenuHandler::decrement(){currentMenu->decrement();isActive=true;}
void MenuHandler::enter(){
    currentMenu = currentMenu->enter(currentMenu);
}
