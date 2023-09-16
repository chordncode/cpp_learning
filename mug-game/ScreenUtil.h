#ifndef SCREENUTIL_H_INCLUDED
#define SCREENUTIL_H_INCLUDED
#include <iostream>
#include <cstdlib>
using namespace std;

class ScreenUtil {
public:
    static void clear() {
        system("clear");
    };
};

#endif