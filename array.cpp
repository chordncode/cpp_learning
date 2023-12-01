#include <iostream>
using namespace std;

int main() {
	int *arr = new int[]{1, 2, 3};
	
	cout << *arr << endl;
	cout << *(arr + 1) << endl;
	cout << *(arr + 2) << endl;

	return 0;
}
