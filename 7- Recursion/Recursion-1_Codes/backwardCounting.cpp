#include<iostream>
using namespace std;
void backwardCounting(int n){
    if(n==0)
        return;
    cout<<n<<" ";
    backwardCounting(n-1);
}
int main(){
    int n;
    cout<<"Enter n\n";
    cin>>n;
    backwardCounting(n);
    return 0;
}