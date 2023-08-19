#include <iostream>
#include <ncurses.h>

int main(){

	int ch;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	while((ch = getch()) != 1){
		switch(ch){
			case KEY_UP: printw("\nup"); break;
			case KEY_DOWN: printw("\ndown"); break;
			case KEY_LEFT: printw("\nleft"); break;
			case KEY_RIGHT: printw("\nright"); break;
			case '\n': printw("\nenter"); break;
			default: printw("%c", ch); break;
		}
	}
	return 0;
}

