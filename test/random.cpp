#include "bits/stdc++.h"
#define ll long long
#define ull unsigned long long
using namespace std;
ll random()
{
    srand((unsigned int)time(0));
    return rand()*rand();
}
void arr(int n,int mod)
{
    for (int i=1;i<=n;i++)
    {
        cout<<random()%mod<<" ";
    }
    cout<<"\n";
}
void tree(int n,int m,int mod)
{

}
signed main()
{
    freopen("data.in","w",stdout);

    return 0;
}