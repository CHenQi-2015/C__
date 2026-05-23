#include<bits/stdc++.h>
using namespace std;
const int max_n=100005;
int n,m,f[max_n][25],l,r,f2[max_n];
void init(){
	for(int i=2;i<=n;i++){
		f2[i]=f2[i>>1]+1;
	}
	for(int j=1;j<=f2[n];j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	return;
}
int query(int lt,int rt){
	int k=f2[rt-lt+1];
	return max(f[lt][k],f[rt-(1<<k)+1][k]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i][0]);
	}
	init();
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}