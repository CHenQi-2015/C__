#include<bits/stdc++.h>
using namespace std;
const int max_v=,max_e=;
int h[max_v],cnt;
struct edge{
	int u;
	int v;
	int nxt;
}e1[max_e],e2[max_e];
void add(int u,int v){
	e1[++cnt]={u,v,h[u]};
	e2[++cnt]={v,u,h[v]};
	h[u]=cnt;
}
int main(){
	cin>>;
	int u,v;
    for(int i=1;i<=;i++){
		cin>>u>>v;
		add(u,v);
    }
    
    return 0;
}
