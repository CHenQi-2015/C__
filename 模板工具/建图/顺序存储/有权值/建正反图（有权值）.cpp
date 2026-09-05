#include<bits/stdc++.h>
using namespace std;
const int max_v=,max_e=;
int h[max_v],cnt;
struct edge{
	int u;
	int v;
	int w;
	int nxt;
}e1[max_e],e2[max_e];
void add(int u,int v,int w){
	e1[++cnt]={u,v,w,h[u]};
	e2[++cnt]={v,u,w,h[v]};
	h[u]=cnt;
}
int main(){
	cin>>;
	int u,v,w;
    for(int i=1;i<=;i++){
		cin>>u>>v>>w;
		add(u,v,w);
    }
    
    return 0;
}
