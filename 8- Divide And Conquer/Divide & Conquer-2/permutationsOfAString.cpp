#include<iostream>
using namespace std;
void printPermutations(string& str, int i){
    // base case
    if(i>=str.length()){
        cout<<str<<" ";
        return;
    }

    for(int j=i; j<str.length();j++){
        swap(str[i], str[j]);
        printPermutations(str, i+1);

        // backtracking - to get the original string
        swap(str[i], str[j]);
    }
}
int main(){
    string str="abc";
    printPermutations(str, 0);
}