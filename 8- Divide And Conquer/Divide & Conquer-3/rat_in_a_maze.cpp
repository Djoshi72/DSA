#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isSafe(int arr[][3], int i, int j,int row, int col, vector<vector<bool>>& visited ){
    //  isSafe dunction checks 3 things. 
    // 1- if i and j are inside bonds of array or not
    // 2- if visited[i][j] marked as false
    // 3- If arr[i][j] is 1
    if((i>=0 && i<row) && (j>=0 && j<col) && (visited[i][j]==false) && (arr[i][j]==1)){
        return true;
    }
    return false;
}
void  solve(int arr[][3],int row,int col,int i,int j, vector<vector<bool>>& visited, vector<string>& path, string output){
    // Base case -> when the rat reached to the destination
    if(i==row-1 && j==col-1){
        path.push_back(output);
        return;
    }
    // Ek case solve-> Call for each direction movements, here 4 movements are allowed
    // left, right, up and down

    // 1-> Down
    if(isSafe(arr, i+1, j, row, col, visited)){
        visited[i+1][j]=true;
        solve(arr, row, col, i+1, j, visited, path, output+'D');
        // Backtarcking
        visited[i+1][j]= false;
    } 

    // 2-> Left
    if(isSafe(arr, i, j-1,row, col, visited)){
        visited[i][j-1]= true;
        solve(arr, row, col, i, j-1, visited,path, output+'L');
        visited[i][j-1]- false;
    }

    // 3-> Right
    if(isSafe(arr, i, j+1, row, col, visited)){
        visited[i][j+1]= true;
        solve(arr, row, col, i, j+1, visited, path, output+'R');
        visited[i][j+1]= false;
    }

    // 4-> Up
    if(isSafe(arr, i-1, j, row, col, visited)){
        visited[i-1][j]= true;
        solve(arr, row, col, i-1, j, visited, path, output+'U');
        visited[i-1][j]=false;
    }

}
int main(){
    int maze[][3]={{1,0,0},{1,1,0},{1,1,1}};
    int row= 3, col=3;
    string output="";
    // 2 EDGE CASES
    // 1-> if starting point(source) is 0
    if(maze[0][0]==0){
        cout<<"Not Possible to reach destination\n";
    }
    // 2-> if destination is 0
    if(maze[row-1][col-1]==0){
        cout<<"Not Possible to reach destination\n";
    }
    vector<vector<bool>>visited(row, vector<bool>(col,0));
    visited[0][0]=1;        //source
    vector<string>path;
    solve(maze, row, col , 0, 0,visited, path, output);
    for(auto i: path){
        cout<<i<<" ";
    }
    return 0;
}