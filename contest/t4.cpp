#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5005];
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
//    freopen("t4.in","r",stdin);
//    freopen("t4.out","w",stdout);
    string s;
    cin>>s;
    ll len=s.size();
    int co=0;
    for (char c:s)
    {
        if (c=='O')co++;
    }
    int val=(s[1]=='I'?1:-1);
    int now=val;
    int ans=val;
    for (int k=2;k<len-1;k++)
    {
        val=(s[k]=='I')?1:-1;
        now=min(val,now+val);
        ans=min(ans,now);
    }
    cout<<co+ans;
    return 0;
}