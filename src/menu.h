#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <curses.h>
#include <functional>
#include <memory>
#include "item.h"


class Menu: public Item, public std::enable_shared_from_this<Menu> {
    public:
		void increment();
		void decrement();
		std::shared_ptr<Item> enter();
		types get_type(){return MENU;};
		std::string get_name(){return name;};
		Menu(std::shared_ptr<Menu> parent, std::string name);
		Menu(std::function<void(void)> quitCallback, std::string name);
		void registerMenuItem(std::shared_ptr<Item> item);
		// std::shared_ptr<Menu> getSelectedSubMenu();
		// std::string getSelectedSubMenuName();
		void print();
		const std::vector<std::string>& getNames();
		int getIdx();
    private:
		std::string name;
		std::vector<std::shared_ptr<Item>> items_list;
		std::vector<std::string> names;
		uint8_t idx=0;
		uint8_t len=0;
		std::shared_ptr<Item> parent;
};

class Callback : public Item, public std::enable_shared_from_this<Item> {
	public:
		virtual types get_type(){return CALLBACK;};
		void increment(){}; /// does nothing
		void decrement(){}; /// does nothing
		std::shared_ptr<Item> enter();
		std::string get_name(){return name;};
		Callback(std::string Name,std::function<void()> Callback);
		std::function<void()> cb;
	private:
		std::string name;
};
