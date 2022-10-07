#ifndef ITEM_H_
#define ITEM_H_
#include <memory>
#include <iostream>

class Item {
	public:
		enum types{INVALID=0,MENU=1,SLIDER=2,CALLBACK=3};
		virtual void increment()=0;
		virtual void decrement()=0;
		virtual std::shared_ptr<Item> enter()=0;
		virtual types get_type(){return INVALID;};
		virtual std::string get_name()=0;
};

#endif // ITEM_H_
