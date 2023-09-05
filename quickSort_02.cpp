#include <iostream>
using namespace std;

void quickSort(int* arr, const int left, const int right);
int partition(int* arr, const int left, const int right);
void swap(int* arr, const int left, const int right);

int main() {
    int arr[] = {4, 7, 5, 8, 6, 2, 3, 1};
    quickSort(arr, 0, sizeof(arr)/sizeof(arr[0]));
    for(int a : arr) {
        cout << a << endl;
    }
    return 0;
}

void quickSort(int* arr, const int left, const int right) {
    if(left >= right) return;
    
    int pivot = partition(arr, left, right);

    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
}

int partition(int* arr, const int left, const int right) {
    int pivot = arr[left];
    int i = left, j = right;

    while(i < j) {
        while(pivot < arr[j]) {
            j--;
        }
        while(i < j && pivot >= arr[i]) {
            i++;
        }
        swap(arr, i, j);
    }

    arr[left] = arr[i];
    arr[i] = pivot;

    return i;
}

void swap(int* arr, const int left, const int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}