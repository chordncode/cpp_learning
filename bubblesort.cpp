#include <iostream>
using namespace std;

int* numArr;
int* splitInputNum(int input);
void bubbleSort();

int main(void){

	int input;

	cout << "Input 6 Numbers : ";
	cin >> input;


	numArr = splitInputNum(input);
	bubbleSort();

	for(int i(0); i < 6; i++){
		cout << numArr[i] << endl; 
	}

	return 0;

}

int* splitInputNum(int input){

	static int numArr[6];

	numArr[0] = input / 100000;
	numArr[1] = (input / 10000) % 10;
	numArr[2] = (input / 1000) % 10;
	numArr[3] = (input / 100) % 10;
	numArr[4] = (input / 10) % 10;
	numArr[5] = input % 10;

	return numArr;
}

void bubbleSort(){

	for(int i(5); i > 0; i--){
		for(int j(0); j < i; j++){
			if(numArr[j] > numArr[j + 1]){
				int temp = numArr[j];
				numArr[j] = numArr[j + 1];
				numArr[j + 1] = temp;
			}
		}
	}	
}
