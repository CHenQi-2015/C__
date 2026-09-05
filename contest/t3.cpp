#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N],b[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
//    freopen("t3.in","r",stdin);
//    freopen("t3.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    ll s=0;
    for (int i=1;i<n;i++)
    {
        if (a[i]==a[i+1])s+=min(b[i],b[i+1]);
    }
    cout<<s;
    return 0;
}