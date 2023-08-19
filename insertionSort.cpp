#include <iostream>
#include <cmath>

using namespace std;

int* numArr;
int* splitInputNum(int input);
void insertionSort();

int main(void){

	int input;
	cout << "Input 6 Numbers : ";
	cin >> input;

	numArr = splitInputNum(input);
	insertionSort();

	for(int i(0); i < 6; i++){
		cout << numArr[i];
	}
	cout << endl;

	return 0;
}

int* splitInputNum(int input){

	static int numArr[6];
	for(int i(0); i < 6; i++){
		numArr[i] = input / (100000 / pow(10, i));
		if(i != 0) numArr[i] %= 10;
	}

	return numArr;
}

void insertionSort(){

}
