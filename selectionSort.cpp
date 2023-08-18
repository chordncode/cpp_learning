#include <iostream>
#include <cmath>
using namespace std;

int* numArr;

int* splitInputNum(int input);
void selectionSort();

int main(void){

	int input;
	cout << "Input 6 Numbers : ";
	cin >> input;

	numArr = splitInputNum(input);
	selectionSort();

	for(int i(0); i < 6; i++){
		cout << numArr[i];
	}

	cout << endl;
	return 0;
}

int* splitInputNum(int input){
	
	static int numArr[6];

	for(int i = 0; i < 6; i++){
		numArr[i] = input / (100000 / pow(10, i));
		if(i != 0) numArr[i] %= 10;		
	}

	return numArr;
}

void selectionSort(){

	for(int i(0); i < 5; i++){
		int min = i;
		for(int j(i + 1); j < 6; j++){
			if(numArr[min] > numArr[j]) min = j;
		}
		int temp = numArr[i];
		numArr[i] = numArr[min];
		numArr[min] = temp;
	}
	
}
