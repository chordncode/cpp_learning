#include <iostream>
#include "CharStack.h"
using namespace std;

int main() {
    CharStack chStk;
    char str[20];
    
    cout << "영어 단어 입력 : ";
    cin >> str;

    char* pt = str;
    while(*pt) {
        chStk.push(*(pt++));
    }
    cout << "단어 출력(역순) : ";
    while(!chStk.isEmpty()) {
        cout << chStk.pop();
    }
    cout << endl;
    return 0;
}