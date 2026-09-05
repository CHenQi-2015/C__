#include <bits/stdc++.h>
using namespace std;
typedef  unsigned long long ull;
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
//    freopen("t1.in","r",stdin);
//    freopen("t1.out","w",stdout);
    ull n;
    cin>>n;
    ull t=n/6;
    int a[6]={0,0,1,2,2,3};
    cout<<(t<<2)+a[n-(t<<2)-(t<<1)];
    return 0;
}
