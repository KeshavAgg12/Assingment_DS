#include<iostream>
using namespace std;
void mergesort(int *arr ,int low ,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void merge(int *arr,int low,int mid,int high){
    int rb_index,temp_beg,lb_index,temp[sizeof(arr)];
    lb_index=low;
    rb_index=mid+1;
    temp_beg=low;
    while((lb_index<=mid)&&(rb_index<=high)){
        if(arr[lb_index]<arr[rb_index]){
            temp[temp_beg]=arr[lb_index];
            lb_index+=1;
        }
        else{
            temp[temp_beg]=arr[rb_index];
            rb_index+=1;
        }
        temp_beg+=1;
    }
    while(lb_index<mid){
        temp[temp_beg]=arr[lb_index];
        temp_beg+=1;
        lb_index+=1;

    }
    while(rb_index<mid){
        temp[temp_beg]=arr[rb_index];
        temp_beg+=1;
        rb_index+=1;

    }
    for(int i=low;i<high;i++){
        arr[i]=temp[i];
    }
}