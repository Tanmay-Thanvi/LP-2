#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++) {
        int m = i;
        for (int j = i; j < n; j++) {
            if(arr[m]>arr[j]){
                m = j;
            }
        }
        if(m != i) swap(arr[m],arr[i]);
    }
    
    for (auto i : arr) {
        cout<<i<<" ";
    }
    return 0;
}