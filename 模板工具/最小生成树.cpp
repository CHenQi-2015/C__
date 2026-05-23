#include<bits/stdc++.h>
using namespace std;
const int max_v=5005,max_e=200005;
int f[max_v],r[max_v],n,m,u,v,w,cnt,ans,tot;
struct edge{
	int u;
	int v;
	int w;
}e[max_e];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
void add(int u,int v,int w){
	e[++cnt]={u,v,w};
}
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
} 
void FILL(int N){
	for(int i=1;i<=N;i++){
		f[i]=i;
	}
	return;
}
bool merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return 0;
	if(f[fx]>=r[fy])f[fy]=fx;
	else f[fx]=fy;
	if(r[fx]==r[fy])r[fx]++;
	return 1;
}
int main(){
    cin>>n>>m;
    FILL(n);
    for(int i=1;i<=m;i++){
    	cin>>u>>v>>w;
    	add(u,v,w);
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
    	 int is=merge(e[i].u,e[i].v);
    	 if(is){
    	 	tot++;
    	 	ans+=e[i].w;
		 }
		 if(tot==n-1){
		 	cout<<ans;
		 	return 0;
		 }
	}
	cout<<"orz";
    return 0;
}
