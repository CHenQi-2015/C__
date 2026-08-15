#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
//    freopen("t2.in","r",stdin);
//    freopen("t2.out","w",stdout);
    int x,y,n;
    cin>>x>>y>>n;
    cout<<n/x+n/y-n/lcm(x,y);
    return 0;
}
