#include<bits/stdc++.h>
using namespace std;
const int N=,W=;
int w[N],v[N],dp[W];
int main()
{
    int sw,n;
    cin>>sw>>n;
    for (int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    for (int i=1;i<=n;i++)
        for (int j=w[i];j<=sw;j++)
            dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
    cout<<dp[sw];
    return 0;
}