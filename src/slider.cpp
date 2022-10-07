#include "slider.h"
#include "item.h"
#include <memory>
#include <string>

Slider::Slider(std::shared_ptr<Item> Parent,std::string Name, std::shared_ptr<int> var,int Increment){
    var_ptr = var;
    increment_by = Increment;
    name = Name;
    parent = Parent;
}
void Slider::decrement(){
    index+=increment_by;
}
void Slider::increment(){
    index-=increment_by;
}
std::shared_ptr<Item> Slider::enter(){
        *var_ptr = index;
        return parent;
}
int Slider::get_index(){
    return index;
}
std::string Slider::get_name(){
    return name;
}
int Slider::get_var_value(){
    return *var_ptr;
}
