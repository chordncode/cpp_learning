#include <iostream>
#include "Complex1.h"
using namespace std;

void Complex1::display() const {
    cout << "(" << rPart;
    if(iPart > 0) {
        cout << " + j" << iPart;
    } else if(iPart < 0) {
        cout << " - j" << iPart;
    }
    cout << ")";
}