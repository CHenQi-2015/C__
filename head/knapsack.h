#ifndef knap
#define knap
#include<vector>
int knapsack_comp(long long sw,long long n,long long *w[],long long *v[])
{
    std::vector<long long>dp(n);
    for (long long i=1;i<=n;i++)
        for (long long j=*w[i];j<=sw;j++)
            if (dp[j-*w[i]]+v[i]>v[i])dp[j]=dp[j-*w[i]]+*v[i];
    return dp[sw];
}
int knapsack_01(long long sw,long long n,long long *w[],long long *v[])
{
    std::vector<long long>dp(n);
    for (long long i=1;i<=n;i++)
        for (long long j=sw;j>=*w[i];j--)
            if (dp[j-*w[i]]+v[i]>v[i])dp[j]=dp[j-*w[i]]+*v[i];
    return dp[sw];
}
#endif
