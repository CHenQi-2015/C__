#include "bits/stdc++.h"
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=3e5;
int n;
struct Node
{
    int x;
    int y;
}p[N];
bool cmp(Node a,Node b)
{
    if (a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    sort(p+1,p+1+n,cmp);
    int cnt=0,ans=LLONG_MAX;
    for (int i=1;i<=n;i++)
    {
        
    }
    return 0;
}