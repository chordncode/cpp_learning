#include <iostream>
#include "./person/Person.h"
using namespace std;

int main() {
    Person* p1 = new Person("김철수", "서울시 서초구");
    Person* p2 = new Person("이다혜", "대전시 유성구");
    p1->print();
    p2->print();
    cout << "주소 변경 : " << endl;
    p1->chAddr("제주시 건입동");
    p1->print();
    delete p1;
    delete p2;
    return 0;
}