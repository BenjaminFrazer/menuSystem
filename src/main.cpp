#include <iostream>
#include "menu.h"
#include "menu_handler.h"
#include "ui.h"

int main(int argc, char *argv[]) {
    UI ui;
    auto cbLambda = [&ui](){ui.quit();};
    auto main = std::make_shared<Menu>(cbLambda);
    auto sub = std::make_shared<Menu>(main);
    auto subsub = std::make_shared<Menu>(sub);
    main->registerItem({"Sub",sub});
    sub->registerItem({"Subsub1",subsub});
    sub->registerItem({"Subsub2",subsub});
    sub->registerItem({"Subsub3",subsub});
    auto mh = std::make_shared<MenuHandler>(main);
    ui.regMenuHandler(mh);
    ui.getInput();
    return 0;
};

