#include<bits/stdc++.h>
using namespace std;nn
const int max_v=,max_e=;
int h[max_v],cnt;
struct edge{
	int u;
	int v;
	int nxt;
}e[max_e];
void add(int u,int v){
	e[++cnt]={u,v,h[u]};
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
