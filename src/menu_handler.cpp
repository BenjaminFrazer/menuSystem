#include "menu_handler.h"
MenuHandler::MenuHandler(std::shared_ptr<Menu> topLevel){
    currentMenu = topLevel;
}
void MenuHandler::increment(){currentMenu->increment();isActive=true;}
void MenuHandler::decrement(){currentMenu->decrement();isActive=true;}
void MenuHandler::enter(){
    if(currentMenu->getIsCallback()){
        auto cb = currentMenu->getSelectedCallback();
        cb();
    }
    if(currentMenu->getSelectedSubMenu()){
        currentMenu = currentMenu->getSelectedSubMenu();
    }
    else{ // do nothing
        if(currentMenu->getIdx()==0){//we must be in the toplevel menu
            isActive=false;
        }
        else{
        std::cout << "Warning: Sub menu Undefined for " << currentMenu->getSelectedSubMenuName() << "\n";
        }
    }
}
void MenuHandler::print(){
    currentMenu->print();
}

