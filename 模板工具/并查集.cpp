#include<bits/stdc++.h>
using namespace std;
const int max_n=100005;
int f[max_n],r[max_n];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
} 
void FILL(int N){
	for(int i=1;i<=N;i++){
		f[i]=i;
	}
	return;
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	if(f[fx]>=r[fy])f[fy]=fx;
	else f[fx]=fy;
	if(r[fx]==r[fy])r[fx]++;
	return;
}
int main(){
    cin>>;
    FILL(n);
    
    return 0;
}
