##
  # menu system
  #
  # @file
  # @version 0.1

all: menu menu_handler ui slider main.cpp
	g++ -g -Wall -o menu_test menu.o menu_handler.o slider.o ui.o main.cpp -lncurses
  # end

menu: menu.cpp
	g++ -g -c -Wall -o menu.o menu.cpp

slider: slider.cpp
	g++ -g -c -Wall -o slider.o slider.cpp

menu_handler: menu menu_handler.cpp
	g++ -g -c -Wall -o menu_handler.o menu_handler.cpp

ui: ui.cpp
	g++ -g -c -Wall -o ui.o ui.cpp
