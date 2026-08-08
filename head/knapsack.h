#ifndef KNAPSACK_H
#define KNAPSACK_H
#include<vector>
using ll=long long;
inline ll knapsack_comp(ll sw,ll n,const ll w[],const ll v[])
{
    //完全背包
    std::vector<ll>dp(sw+5,0);
    for (ll i=1;i<=n;i++)
    {
        for (ll j=w[i];j<=sw;j++)
        {
            //正序遍历
            if (dp[j-w[i]]+v[i]>dp[j])
            {
                dp[j]=dp[j-w[i]]+v[i];
            }
        }
    }
    return dp[sw];
}
inline ll knapsack_01(ll sw,ll n,const ll w[],const ll v[])
{
    //01背包
    std::vector<ll>dp(sw+5,0);
    for (ll i=1;i<=n;i++)
    {
        for (ll j=sw;j>=w[i];j--)
        {
            //逆序遍历
            if (dp[j-w[i]]+v[i]>dp[j])
            {
                dp[j]=dp[j-w[i]]+v[i];
            }
        }
    }
    return dp[sw];
}
#endif