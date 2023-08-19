#include <iostream>
#include <termios.h>
#include <unistd.h>

void enableRawMode(){
	struct termios raw;
	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

char getArrow(){

	enableRawMode();

	char c;
	if(read(STDIN_FILENO, &c, 1) == -1){
		return 'E';
	}

	if(c == '\x1b'){
		char seq[2];
		if(read(STDIN_FILENO, &seq[0], 1) != 1){
			return 'E';
		}
		if(read(STDIN_FILENO, &seq[1], 1) != 1){
			return 'E';
		}

		if(seq[0] == '['){
			switch(seq[1]){
				case 'A':
					return 'u';
				case 'B':
					return 'd';
				case 'C':
					return 'r';
				case 'D':
					return 'l';
			}
		}
	}

	if(c == '\r') return 'e';
	if(c == 'q') return 'q';

	return 'E';

}
