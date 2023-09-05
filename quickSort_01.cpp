#include <iostream>
using namespace std;

void quickSort(int* arr, int i, int j);
int partition(int* arr, int i, int j);
void swap(int* arr, int i, int j);

int main() {
    int arr[] = {5, 7, 2, 3, 6, 4, 1, 8};
    quickSort(arr, 0, sizeof(arr)/sizeof(arr[0]));
    
    for(int a : arr) {
        cout << a << endl;
    }
    return 0;
}

void quickSort(int* arr, int i, int j) {
    if(i >= j) return;

    int pivot = partition(arr, i, j);

    quickSort(arr, i, pivot - 1);
    quickSort(arr, pivot + 1, j);
}

int partition(int* arr, int i, int j) {
    int pivot = arr[i];
    int left = i, right = j;

    while(left < right) {
        while(pivot < arr[right]) {
            right--;
        }
        while(left < right && pivot >= arr[left]) {
            left++;
        }
        swap(arr, left, right);
    }
    arr[i] = arr[left];
    arr[left] = pivot;

    return left;
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

