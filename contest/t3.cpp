#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m,a[N];
bool check(ll mid){
    int d=1;
    ll now=0;
    bool free=0;
    for (int i=1;i<=n;i++)
    {
        ll t=a[i];
        if (now+t<=mid){
            now+=t;
        }
        else
        {
           if (!free)free=1;
           else
           {
               d++;
               if (d>m)return 0;
               now=t;
               free=0;
               if (now>mid)
               {
                   if (!free)
                   {
                       free=1;
                       now=0;
                   }
               }
           }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
//    freopen("t3.in","r",stdin);
//    freopen("t3.out","w",stdout);
    cin>>n>>m;
    ll sum=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    ll lt=0,rt=sum,ans=sum;
    while (lt<=rt)
    {
        ll mid=lt+((rt-lt)>>1);
        if (check(mid))
        {
            ans=mid;
            rt=mid;
        }
        else lt=mid;
    }
    cout<<ans;
    return 0;
}
