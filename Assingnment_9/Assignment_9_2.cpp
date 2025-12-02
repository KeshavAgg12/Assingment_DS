#include<iostream>
using namespace std;

void improved_selection(int* arr, int n){
    int start = 0;
    int end = n - 1;

    while(start < end){

        int minIndex = start;
        int maxIndex = start;

      
        for(int i = start; i <= end; i++){
            if(arr[i] < arr[minIndex])
                minIndex = i;
            if(arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;

       
        if(maxIndex == start)
            maxIndex = minIndex;

        temp = arr[end];
        arr[end] = arr[maxIndex];
        arr[maxIndex] = temp;

        start++;
        end--;
    }
}
