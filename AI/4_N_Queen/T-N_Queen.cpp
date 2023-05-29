#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

void n_queen(int col,vector<string> &board,vector<bool> &leftrow,vector<bool> &upperdiagonal,vector<bool> &lowerdiagonal,int n){
    
    if(col == n){
        ans.push_back(board);
        return;
    }
    
    for (int row = 0; row < n; row++) {
        if(leftrow[row] == 0 and upperdiagonal[n-1-row+col] == 0 and lowerdiagonal[col+row] == 0 ){
            leftrow[row] = 1;
            upperdiagonal[n-1-row+col] = 1;
            lowerdiagonal[col+row] = 1;
            
            board[row][col] = 'Q';
            n_queen(col+1,board,leftrow,upperdiagonal,lowerdiagonal,n);
            board[row][col] = '.';
            
            leftrow[row] = 0;
            upperdiagonal[n-1-row+col] = 0;
            lowerdiagonal[col+row] = 0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    
    vector<bool> leftrow(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
    n_queen(0,board,leftrow,upperdiagonal,lowerdiagonal,n);
    
    cout<<"\nTotal Solutions ("<<ans.size()<<") : \n"<<endl;
    for (auto i : ans) {
        for (auto j : i) {
            cout<<j<<endl;
        }
        cout<<endl;
    }
    return 0;
}