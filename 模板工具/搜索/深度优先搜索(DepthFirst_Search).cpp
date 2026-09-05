#include<bits/stdc++.h>
using namespace std;
int vis[];
void DepthFirst_Search(int i){
	if(i>=n){

		return;
	}
	if(vis[i]){
		return vis[i];
	}
	for(int j=1;j<=;j++){
		DepthFirst_Search(i+j);
	}
}
int main(){

	DepthFirst_Search();
    return 0;
}
