#include <bits/stdc++.h>
using namespace std;

#define int long long

int pub_k;
int pri_k;
int n;

vector<int> primes;

void compute_primes()
{
    primes.push_back(2);
    for (int i = 2; i < 100; i++)
    {
        int flag = 0;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            primes.push_back(i);
        }
    }
}

void set_keys()
{
    int p1 = 29;
    int p2 = 23;

    n = p1 * p2;
    int phi = (p1 - 1) * (p2 - 1);
    int e = 2;
    while (true)
    {
        if (__gcd(e, phi) == 1)
        {
            break;
        }
        e++;
    }
    pub_k = e;
    int d = 1;
    while (true)
    {
        if ((d * e) % phi == 1)
        {
            break;
        }
        d++;
    }
    pri_k = d;
}

vector<int> encode(string s)
{
    vector<int> ans;
    for (auto x : s)
    {
        int e = pub_k;
        int temp = 1;
        while (e--)
        {
            temp *= (int)(x);
            temp %= n;
        }
        ans.push_back(temp);
    }
    return ans;
}

string decode(vector<int> encoded)
{
    string s = "";
    for (auto x : encoded)
    {
        int temp = 1;
        int d = pri_k;
        while (d--)
        { 
            temp *= x;
            temp %= n;
        }
        s += (char)(temp);
    }
    return s;
}

signed main()
{

    string plain_txt;
    cout << "Enter message to encode: ";
    // cin>>plain_txt;
    getline(cin, plain_txt);

    compute_primes();
    set_keys();

    vector<int> encoded = encode(plain_txt);

    cout << "\nThe encoded message is: ";
    for (auto x : encoded)
    {
        cout << x;
    }
    cout << endl;

    string decrypted_txt = decode(encoded);

    cout << "\nThe decrypted message is: ";
    cout << decrypted_txt << endl
         << endl;

    return 0;
}