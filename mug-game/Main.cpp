#include <iostream>
#include "ScreenUtil.h"
#include "MainMenu.h"
#include "MenuTypes.h"
using namespace std;

int main() {
    MenuTypes mt;
    MainMenu mainMenu;
    ScreenUtil::clear();
    while(1) {
        switch(mt) {
            case MenuTypes::EXIT:
                return 0;
            case MenuTypes::MAINMENU: default:
                mt = mainMenu.mainMenu();
                break;
        }
    }
    return 0;
}