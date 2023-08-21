#include <iostream>
#include <cmath>

using namespace std;

int* numArr;

int* splitInputNum(int num);
void bubbleSort();

int main(){
	int input;

	while(1){
		cout << "Input 6 Numbers : ";
		cin >> input;
		if(input > 100000 && input < 999999) break;	
	}

	numArr = splitInputNum(input);
	bubbleSort();

	for(int i(0); i < 6; i++){
		if(i > 0) cout << ", ";
		cout << numArr[i];
	}
	cout << endl;

	return 0;
}

int* splitInputNum(int num){
	
	static int numArr[6];

	for(int i(0); i < 6; i++){
		numArr[i] = num / (100000 / pow(10, i)); 
		if(i > 0) numArr[i] %= 10;
	}

	return numArr;
}

void bubbleSort(){

	for(int i(5); i > 0; i--){
		for(int j(0); j < i; j++){
			if(numArr[j] > numArr[j+1]){
				int temp = numArr[j];
				numArr[j] = numArr[j + 1];
				numArr[j + 1] = temp;
			}
		}
	}

}
