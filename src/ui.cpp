#include "ui.h"
#include "item.h"
#include "menu_handler.h"
#include "slider.h"
#include <cstdlib>
#include <ctime>
#include <curses.h>
#include <iostream>
#include <memory>
#include <string>

/**
   *exit the menu */
void UI::quit(){
    ptrMH->reset();
    menuActive = false;
    print();
}
void UI::terminate(){
    endwin();
    exit(0);
}
Box::Box(int x,int y,int Width,int Height){
    origin_x = x;
    origin_y = y;
    height = Height;
    width = Width;
    window = newwin(Height,Width,y, x);
    if (window==0){
        std::cout << "Window Initialisation error\n";
        exit(0);
    }
        }
void Box::draw(){
    wclear(window);
    box(window,0,0);
    wrefresh(window);
}
void Box::print_ln(std::string str,int row){
        mvaddstr(row+origin_y+1, origin_x+2, str.data());
}
void Box::highlight_row(int row){
    mvaddch(row+origin_y+1, origin_x+1, '>');
}
void UI::init(){
    initCurses();
    initscr();
    maxCols = COLS;
    maxLines = LINES;
    isInit = true;
}
UI::UI(){
    init();
    menu_box=Box(0,0,maxCols,maxLines);
}

void UI::regMenuHandler(std::shared_ptr<MenuHandler> MenuHandler){
    ptrMH = MenuHandler;
}

UI::UI(std::shared_ptr<MenuHandler> MenuHandler){
    init();
    ptrMH= MenuHandler;
    menu_box=Box(0,0,maxCols,maxLines);
}
void UI::print(){
    menu_box.draw();
    if (ptrMH && menuActive){
        switch (ptrMH->currentItem->get_type()) {
            case Item::SLIDER:
                display_slider(ptrMH->currentItem);
                break;
            case Item::CALLBACK:
                std::cout << "callback\n";
                break;
            case Item::INVALID:
                std::cout << "invalid\n";
                break;
            case Item::MENU:
                display_menu(ptrMH->currentItem);
                break;
        }
    }
    else{
        menu_box.print_ln("Menu Inactive", 1);
    }
}

void UI::display_slider(std::shared_ptr<Item> SLIDER){
    auto current_slider = std::dynamic_pointer_cast<Slider>(SLIDER);
    menu_box.print_ln(current_slider->get_name(), 0);
    menu_box.print_ln(std::to_string(current_slider->get_index()), 1);
    refresh();
};

void UI::display_menu(std::shared_ptr<Item> MENU){
    auto current_menu = std::dynamic_pointer_cast<Menu>(MENU);
    auto names = current_menu->getNames();
    // clear();
    for(uint i=0;i<names.size();i++){
        menu_box.print_ln(names.at(i), i);
    };
    menu_box.highlight_row(current_menu->getIdx());
    refresh();
};
void UI::getInput(){
    while(true){
        int input = getch();
        menuActive = true;
        switch (input) {
            case KEY_UP:
                ptrMH->decrement();
                break;
            case 'k':
                ptrMH->decrement();
                break;
            case 'j':
                ptrMH->increment();
                break;
            case KEY_DOWN:
                ptrMH->increment();
                break;
            case '\n':
                ptrMH->enter();
                break;
            case (int)'q':
                terminate();
            default:
                break;
        }
        print();
    }
}

void UI::initCurses(){
    initscr();
    cbreak();
    noecho();
    clear();
    isInit = true;
    keypad(stdscr, TRUE); //Enables keypad for default window
}
