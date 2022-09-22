#include "ui.h"

void UI::quit(){
    endwin();
    exit(0);
}

void UI::init(){
    initCurses();
    initscr();
    maxCols = COLS-1;
    maxLines = LINES-1;
    isInit = true;
}

UI::UI(){
    init();
}

void UI::regMenuHandler(std::shared_ptr<MenuHandler> MenuHandler){
    ptrMH = MenuHandler;
}

UI::UI(std::shared_ptr<MenuHandler> MenuHandler){
    init();
    ptrMH= MenuHandler;
}
void UI::print(){
    if (ptrMH){
        auto names = ptrMH->currentMenu->getNames();
        // clear();
        int height = maxLines+1;
        int width = maxCols/2;
        WINDOW *window = newwin(height, width, 0,0);
        box(window,0,0);
        wrefresh(window);
        for(int i=0;i<names.size();i++){
            auto string = names.at(i);
            mvaddstr(i+1, 2, string.data());
        };
        mvaddch(1+ptrMH->currentMenu->getIdx(), 1, '>');
        refresh();
    }
}
void UI::getInput(){
    while(true){
        int input = getch();
        switch (input) {
            case KEY_UP:
                ptrMH->decrement();
                break;
            case KEY_DOWN:
                ptrMH->increment();
                break;
            case '\n':
                ptrMH->enter();
                break;
            case (int)'q':
                quit();
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