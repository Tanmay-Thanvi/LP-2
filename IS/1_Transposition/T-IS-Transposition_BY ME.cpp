#include<bits/stdc++.h> 
using namespace std;

int main(){
    string k,p,space;
    cout<<"Enter Plain text : ";
    getline(cin,p);
    cout<<"Enter key : ";
    cin>>k;
    
    space = "";
    
    if(p.size()%k.size()){
        for (int i = 0; i < k.size() - (p.size()%k.size()); i++) {
            space += ' ';
        }
    }
    p += space;
    
    vector<vector<char>> table;
    
    int c = 0;
    for (int i = 0; i < k.size(); i++) {
        vector<char> new_v;
        for (int j = 0; j < k.size(); j++) {
            new_v.push_back(p[c]);
            c++;
        }
        table.push_back(new_v);
    }
    c = 0;
    map<char,vector<char>> mp;
    for (auto i : k) {
        vector<char> new_v;
    for (int i = 0; i < k.size(); i++) {
        new_v.push_back(table[i][c]);
    }
        c++;
        mp[i] = new_v;
    }
    string cipher = "";
    for (auto i : mp) {
        for (auto j : i.second) {
            cipher += j;
        }
    }
    
    cout<<cipher<<endl;
    
    string old_k = k;
    map<char,vector<char>> mp1;
    sort(k.begin(),k.end());
    int s = 0;
    for (auto i : k) {
        
        vector<char> new_v;
        for (int a = 0; a < k.size(); a++) {
            new_v.push_back(cipher[s*k.size()+a]);
        }
        s++;
        mp1[i] = new_v;
    }
    string plain[k.size()][k.size()];
    int a = 0;
    for (auto i : old_k) {
        int b = 0;
        for (auto j : mp1[i]) {
            plain[b][a] = j;
            b++;
        };
        a++;
    }
    string final = "";
    for (int i = 0; i < k.size(); i++) {
        for (int j = 0; j < k.size(); j++) {
            final += plain[i][j];
        }
    }
    cout<<final<<endl;
}