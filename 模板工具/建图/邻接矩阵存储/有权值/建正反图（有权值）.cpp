#include<bits/stdc++.h>
using namespace std;
const int max_v=;
int g1[max_v][max_v],g2[max_v][max_v]; 
int main(){
	cin>>;
	int u,v,w;
    for(int i=1;i<=;i++){
		cin>>u>>v>>w;
		g1[u][v]=w;
		g2[v][u]=w;
    }
    
    return 0;
}
