#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int tot,h[N];
struct node
{
    int u,v,nxt;
}e[N];
void add(int u,int v)
{
    e[++tot]={u,v,h[u]};
    h[u]=tot;
}
int n,dep[N];
bool vs[N];
void dfs(int r,int f)
{
    dep[r]=f+1;
    vs[r]=1;
    for (int i=h[r];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if (!vs[v])
        {

        }
    }
}
signed main()
{
    cin>>n;
    int u,v;
    for (int i=1;i<=n;i++)
    {
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    return 0;
}