#pragma once
#include "item.h"
#include <memory>
#include <string.h>
#include <string>

class Slider: public Item{
    public:
        Slider(std::shared_ptr<Item> Parent,std::string Name,std::shared_ptr<int> var,int increment);
        void increment();
        void decrement();
        std::shared_ptr<Item> enter();
        types get_type(){return SLIDER;};
        std::string get_name();
        int get_index();
        int get_var_value();
    private:
        int index=0;
        std::shared_ptr<Item> parent;
        std::string name;
        std::shared_ptr<int> var_ptr;
        int increment_by;
};
