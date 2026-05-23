#include<bits/stdc++.h>
using namespace std;
const int max_n=,max_m=;
char a[max_n][max_m];
int ans,n,m;
void dfs(int x,int y){
    a[x][y]=0;
    int dx,dy;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            dx=x+i;
            dy=y+j;
            if(dx>=0&&dx<=n&&dy>=0&&dy<m&&a[dx][dy]){
                dfs(dx,dy);
            }
        }
    }
    return;
} 
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
    	cin>>a[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
