#include <iostream>
#include <cstring>
#include "Person.h"
using namespace std;

Person::Person(const char* name, const char* addr) {
    cout << "생성자 시작" << endl;
    this->name =  new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->addr = new char[strlen(addr) + 1]; 
    strcpy(this->addr, addr);
    cout << "생성자 실행 완료" << endl;
};

Person::~Person() {
    cout << "소멸자 시작" << endl;
    delete [] name;
    delete [] addr;
    cout << "소멸자 실행 완료" << endl;
};

void Person::print() {
    cout << addr << "에 사는 " << name << "입니다." << endl;
};

void Person::chAddr(const char* newAddr) {
    delete [] addr;
    addr = new char[strlen(newAddr) + 1];
    strcpy(addr, newAddr);
};