#include<iostream>
using namespace std;

int partition_func(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;  
}

void quick_sort(int* arr, int low, int high){
    if(low < high){
        
        int pivotIndex = partition_func(arr, low, high);

        quick_sort(arr, low, pivotIndex - 1);   
        quick_sort(arr, pivotIndex + 1, high);  
    }
}
