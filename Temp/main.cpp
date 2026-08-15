#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    string s;
    ll n;
    cin>>s>>n;
    ll l=s.size();
    while (l<=n)
    {
        s=s+s[l-1]+s.substr(0,l-1);
        l<<=1;
    }
    cout<<s[n-1];
    return 0;
}