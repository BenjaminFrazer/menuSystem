#include <iostream>
#include "menu.h"
#include "menu_handler.h"
#include "ui.h"

int main(int argc, char *argv[]) {
    UI ui;
    auto cbLambda = [&ui](){ui.quit();};
    auto main = std::make_shared<Menu>(cbLambda,"Main");
    auto sub = std::make_shared<Menu>(main, "sub");
    auto subsub = std::make_shared<Menu>(sub, "subsub");
    main->registerMenuItem(sub);
    sub->registerMenuItem(subsub);
    sub->registerMenuItem(subsub);
    sub->registerMenuItem(subsub);
    auto mh = std::make_shared<MenuHandler>(main);
    ui.regMenuHandler(mh);
    ui.getInput();
    return 0;
};

