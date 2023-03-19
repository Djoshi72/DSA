#include<iostream>
using namespace std;
int partition(int* arr, int s , int e){
    int pivotIndex= s;
    int pivotElment = arr[s];
    int cnt=0; 

    // this loop will count all the elements less then or equals to pivot  element 
    for(int i=s+1; i<=e;i++){
        if(arr[i]<=arr[pivotIndex])
            cnt++;
    }
    // right index is the correct index of pivot element
    int rightIndex= s+cnt;
    // Place pivot element in it's correct position
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    // place all the elements less than or equals to the pivot element in the left side of array 
    // and the elements which are greater than pivot element place them into the right side of pivot element
    int i =s, j=e;
    // /i is pointing to the first and j is pointing to the last element of the array
    // and pivotIndex is pointing to the index of pivot element
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivotElment)
            i++;
        while(arr[j]>pivotElment)
            j--;
        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i], arr[j]);
    }
    return pivotIndex;
}
void quickSort(int* arr, int s, int e){
    if(s>=e)
        return;
    int p= partition(arr, s,e);
    // Recursive call for left side of pivot element
    quickSort(arr, s,p-1);
    //Recursive call for right side of pivot element
    quickSort(arr,p+1, e);
}
void printArray(int* arr, int n){
    for(int i=0; i<n;i++)   
        cout<<arr[i]<<" ";
}
int main(){
    int arr[]={1,6,8,4,3,9,4};
    int n= 7;
    cout<<"Before Quick Sort \n";
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    cout<<"After Ouick Sort \n";
    printArray(arr, n);
    return 0;
}