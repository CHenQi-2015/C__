#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
int n;
struct stu
{
    int id,c,m,e,s;
}a[305];
inline bool cmp(stu x,stu y)
{
    return (x.s!=y.s?x.s>y.s:(x.c!=y.c?x.c>y.c:x.id<y.id));
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
//    freopen("t2.in","r",stdin);
//    freopen("t2.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].c>>a[i].m>>a[i].e;
        a[i].id=i;
        a[i].s=a[i].c+a[i].m+a[i].e;
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=5;i++)
    {
        cout<<a[i].id<<" "<<a[i].s<<"\n";
    }
    return 0;
}
