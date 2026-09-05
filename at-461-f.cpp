#include "bits/stdc++.h"
#define int long long
using namespace std;
int n,k[105],a[105][105],tot[105];
signed main() {
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>k[i];
        for (int j=1;j<=k[i];j++)
        {
            int v;
            cin>>v;
            a[v][++tot[v]]=i;
        }
    }
    for (int i=1;i<=n;i++)
    {
        cout<<tot[i]<<" ";
        for (int j=1;j<=tot[i];j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
