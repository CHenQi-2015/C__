#include<bits/stdc++.h>
using namespace std;
const int max_u=,max_e=;
int h[max_u],cnt;
struct edge{
	int u;
	int v;
	int w;
	int lst;
}e[max_e];
void add(int u,int v,int w){
	e[++cnt]={v,u,w,h[v]};
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
