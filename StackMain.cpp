#include <iostream>
#include "StackT.h"
using namespace std;

int main(){
	Stack<int> si(50);
	si.push(5);
	si.push(10);
	cout << "INT STACK : ";
	while(!si.empty()) {
		cout << si.pop();
	}
	cout << endl;

	return 0;
}
