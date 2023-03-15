#include<iostream>
using namespace std;
void forwardCounting(int n){
    if(n==0)    
        return;
    forwardCounting(n-1);
    cout<<n<<" ";
}
int main(){
    int n ;
    cout<<"Enter n\n";
    cin>>n;
    forwardCounting(n);
    return 0;
}