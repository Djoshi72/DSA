#include<iostream>
using namespace std;

// fibonacci series 0, 1, 1 ,2,3,5,...... 
// where 0 is 0th element of fib series and 1 is first element of fib series.
int fib(int n){
    if(n==0 || n==1)
        return n;
    return fib(n-1)+fib(n-2);
}

// fibonacci series 0, 1, 1 ,2,3,5,...... 
// where 0 is 1st element of fib series and 1 is second element of fib series.
int fib2(int n){
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return fib2(n-1)+fib2(n-2);
}
int main(){
    int n;
    cout<<"Enter n\n";
    cin>>n;
    cout<<"Ans from function fib is: "<<fib(n)<<endl;
    cout<<"Ans from function fib2 is: "<<fib2(n)<<endl;
    return 0;
}