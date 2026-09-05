#include<bits/stdc++.h>
using namespace std;
const int max_v=,max_e=;
int vs[max_u];
priority_queue<int>pq;
void Topo_Sort(){
	for(int i=1;i<=n;i++){
        if(!vs[i])pq.push(-i);
    }
	while(pq.size()){
		int u=-pq.top();
		pq.pop();
		cout<<u<<' ';
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].v;
			vs[v]--;
			if(vs[v]==0)pq.push(-v);
		}
	}
}
int main(){
	
    Topo_Sort();
    
    return 0;
}
