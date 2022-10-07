#include <iostream>
#include <memory>
#include "menu.h"
#include "slider.h"
#include "menu_handler.h"
#include "ui.h"

int main(int argc, char *argv[]) {
    UI ui;
    auto cbLambda = [&ui](){ui.quit();};
    auto terminateLambda = [&ui](){ui.terminate();};
    auto main = std::make_shared<Menu>(cbLambda,"Main");
    auto sub = std::make_shared<Menu>(main, "Sub");
    auto subsub = std::make_shared<Menu>(sub, "Subsub");
    auto var = std::make_shared<int>(0);
    auto slider = std::make_shared<Slider>(sub,"Set test variable",var,2);
    auto terminateCB = std::make_shared<Callback>("Terminate Application",terminateLambda);
    main->registerMenuItem(sub);
    main->registerMenuItem(terminateCB);
    sub->registerMenuItem(subsub);
    sub->registerMenuItem(subsub);
    sub->registerMenuItem(subsub);
    sub->registerMenuItem(slider);
    subsub->registerMenuItem(main);
    auto mh = std::make_shared<MenuHandler>(main);
    ui.regMenuHandler(mh);
    ui.getInput();
    return 0;
};

