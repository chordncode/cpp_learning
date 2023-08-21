#include <iostream>
#include <cmath>

using namespace std;

int* numArr;
int* splitInputNum(int input);
void insertionSort();

int main(void){

	int input;

	while(1){
		cout << "Input 6 Numbers : ";
		cin >> input;

		if(input > 100000 && input < 999999) break;
	}

	numArr = splitInputNum(input);
	insertionSort();

	for(int i(0); i < 6; i++){
		if(i > 0) cout << ", ";
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

	for(int i(1); i < 6; i++){
		int pick = numArr[i];	
		for(int j(i); j > 0; j--){
			if(numArr[j] < numArr[j-1]){
				int temp = numArr[j];
				numArr[j] = numArr[j - 1];
				numArr[j - 1] = temp;
			} else {
				numArr[j] = pick;
				break;
			}
		}
	}

}
