#include<bits/stdc++.h>
using namespace std;
const int max_v=,max_e=;
int dist[max_v],h[max_v],cnt,vs[max_v];
priority_queue<pair<int, int> >pq;
void dijkstra(int s){
    dist[s]=0;
    pq.push({0,s});
    while(pq.size()) {
		pair<int,int>pr=pq.top();
		int u=pr.second;
        pq.pop();
        if(vs[u])continue;
        vs[u]=1;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(dist[u]+e[i].w<dist[v]){
				dist[v]=dist[u]+e[i].w;
				pq.push({-dist[v],v});
			}
		}
    }
    return;
}
int main(){
	memset(dist,0x3f,sizeof(dist));
	
    dijkstra();
    
    return 0;
}
