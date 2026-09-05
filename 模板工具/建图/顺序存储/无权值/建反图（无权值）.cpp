#include<bits/stdc++.h>
using namespace std;
const int max_v=,max_e=;
int h[max_u],cnt;
struct edge{
	int u;
	int v;
	int lst;
}e[max_e];
void add(int u,int v){
	e[++cnt]={v,u,h[v]};
	h[u]=cnt;
}
int main(){
	cin>>;
	int u,v,w;
    for(int i=1;i<=;i++){
		cin>>u>>v;
		add(u,v);
    }
    
    return 0;
}
