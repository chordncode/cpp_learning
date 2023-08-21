#include <iostream>
#include <cmath>
using namespace std;

int* numArr;

void splitInputNum(int input);
void quickSort(int left, int right);
int partition(int left, int right);
void swap(int i, int j);

int main(){

	int input;

	while(1){
		cout << "Input 6 Numbers : ";
		cin >> input;

		if(input > 100000 && input < 999999) break;
	}

	splitInputNum(input);
	quickSort(0, 5);

	for(int i = 0; i < 6; i++){
		if(i != 0) cout << ", ";
		cout << numArr[i];
	}
	cout << endl;
	
	return 0;
}

void splitInputNum(int input){
	
	static int inputs[6];

	for(int i = 0; i < 6; i++){
		inputs[i] = input / (100000 / pow(10, i));
		if(i != 0) inputs[i] %= 10;
	}

	numArr = inputs;
}

void quickSort(int left, int right){

	if(left >= right) return;

	int pivot = partition(left, right);

	quickSort(left, pivot - 1);
	quickSort(pivot + 1, right);

}

int partition(int left, int right){

	int pivot = numArr[left];

	int i = left, j = right;

	while(i < j){
		while(pivot < numArr[j]){
			j--;
		}
		while(i < j && pivot >= numArr[i]){
			i++;
		}
		swap(i, j);
	}

	numArr[left] = numArr[i];
	numArr[i] = pivot;

	return i;
}

void swap(int i, int j){
	int temp = numArr[i];
	numArr[i] = numArr[j];
	numArr[j] = temp;
}
