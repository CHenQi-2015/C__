#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
//    freopen("t1.in","r",stdin);
//    freopen("t1.out","w",stdout);
    string s;
    cin>>s;
    int cnt[26]={};
    for (char c:s)
    {
        cnt[c-'a']++;
    }
    int ans=0;
    for (int i=0;i<26;i++)
    {
        ans=max(ans,cnt[i]);
    }
    cout<<ans;
    return 0;
}
