#include <iostream>
#include "MenuTypes.h"
#include "ScreenUtil.h"
#include "MainMenu.h"
using namespace std;

MenuTypes MainMenu::mainMenu() const {
    int input = 0;
    while(1) {
        cout << "1. 게임시작" << endl;
        cout << "2. 불러오기" << endl;
        cout << "3. 게임종료" << endl;
        cout << "번호를 입력해주세요 : ";
        cin >> input;

        switch(input) {
            case 1:
                cout << "게임시작";
                return MenuTypes::MAINMENU;
            case 2:
                cout << "불러오기";
                return MenuTypes::MAINMENU;
            case 3:
                cout << "게임종료";
                return MenuTypes::EXIT;
        }
    }
}