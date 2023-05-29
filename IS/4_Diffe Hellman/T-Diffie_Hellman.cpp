#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a,ll b, ll c){
    if(b == 1) return a;
    return (((ll)pow(a, b)) % c);
}

int main()
{
    ll alpha,q;
    q = 17, alpha = 3;
    ll s_p_k = 4, r_p_k = 6;
    
    ll p_c_s = power(alpha,s_p_k,q);
    ll p_c_r = power(alpha,r_p_k,q);

    ll final_key_sender = power(p_c_r,s_p_k,q);
    ll final_key_reciever = power(p_c_s,r_p_k,q);
    
    cout<<final_key_reciever<<" "<<final_key_sender<<endl;
    return 0;
}