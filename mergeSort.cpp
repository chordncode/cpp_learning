#include <iostream>
using namespace std;

void mergeSort(int* arr, int left, int right);
void merge(int* arr, int left, int middle, int right);

int main() {

    int arr[] = {5, 7, 4 ,6 ,3 ,8 ,1 ,2};
    cout << "The Array before be sorted : ";
    for(int a : arr) {
        cout << a << " ";
    }
    cout << endl;

    mergeSort(arr, 0, sizeof(arr)/sizeof(arr[0]));

    cout << "The Array after be sorted : ";
    for(int a : arr) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}

// do merge sort
void mergeSort(int* arr, int left, int right) {

    if(left >= right) return;
    
    // get the middle position of the array
    int middle = left + (right - left) / 2;
    
    // sort each left and right side array
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);

    // merge the two sorted array
    merge(arr, left, middle, right);
}

// merge the two sorted array
void merge(int* arr, int left, int middle, int right) {

    int n1 = middle - left + 1;
    int n2 = right - middle;

    // create the arrays that will be used temporarily
    int leftArr[n1];
    int rightArr[n2];

    // copy the data from the array to the temp arrays
    for(int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    // merge the temp arrays in one
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // copy the last elements
    while(i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}