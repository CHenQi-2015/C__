#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,T=1e9+5;
const long long inf=-(1LL<<60);
int k[N];
vector<long long>f(T);
int main() {
    int n,t,a,b;
    cin >> n >> t >> a >> b;
    for (int i=1;i<=n;i++)
    {
        cin>>k[i];
    }
    sort(k+1,k+1+n);
    for (int i=1;i<=n;i++)
    {
        f[i]=inf;
    }
    f[0]=0;
    long long ans=0;
    for (int i=1;i<=n;i++)
    {
        vector<long long>nf(t+1,inf);
        for (int j=1;j<=t;j++)
        {
            if (f[j]==inf)continue;
            if (j+a<=t)nf[j+a]=max(nf[j+a],f[j]+a[i]);
            if (j+b<=t)nf[j+b]=max(nf[j+b],f[j]);
        }
        f=nf;
        for (int j=0;j<=t;j++)if (f[j]!=inf)ans=max(ans,f[j]);
    }

    cout<<ans;
    return 0;
}
