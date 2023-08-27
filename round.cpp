#include <iostream>
using namespace std;

double roundDouble(double x, int d = 0);

int main(){
    double a;
    cout << "값 : ";
    cin >> a;
    cout << "반올림 : " << roundDouble(a) << endl;
    cout << "         " << roundDouble(a, 1) << endl;
    cout << "         " << roundDouble(a, 2) << endl;
    cout << "         " << roundDouble(a, 3) << endl;
    cout << "         " << roundDouble(a, 4) << endl;
    return 0;
}

double roundDouble(double x, int d){
    double a = x >= 0 ? 0.5 : -0.5;
    double pow10 = pow(10, d);
    return trunc(x * pow10 + a) / pow10;
}