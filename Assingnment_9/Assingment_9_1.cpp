#include<iostream>
using namespace std;
void selection_sort(int *Arr,int n){
    for(int i=0;i<n;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(Arr[j]<Arr[minIndex]){
                minIndex=j;
            }
        }
        int temp=Arr[i];
        Arr[i]=Arr[minIndex];
        Arr[minIndex]=temp;
    }
}