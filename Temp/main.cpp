#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,m,s,h[N],ans=0x3f3f3f3f,cnt;
struct node
{
    int u,v,w,nxt;
}e[N];
inline void add(int u,int v,int w)
{
    e[++s]={u,v,w,h[u]};
    h[u]=s;
}
int dfs(int u,int ed)
{
    if (cnt>m)
    {
        cnt=0;
        return -1;
    }
    if (u==ed)return 0;
    int t=0x3f3f3f3f;
    for (int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        cnt++;
        int nt=dfs(v,ed);
        if (nt==-1)continue;
        t=min(t,e[i].w+nt);
        cnt=0;
    }
    return t;
}
int main()
{
    cin>>n>>m;
    for (int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        add(u,v,w);
    }
    for (int i=2;i<=n;i++)
    {
        ans=min(ans,dfs(1,i)+dfs(i,1));
    }
    cout<<ans;
    return 0;
}