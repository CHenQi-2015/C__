#include<bits/stdc++.h>
#define max_n 10000000
using namespace std;
int n,a[max_n],dp[max_n];
void lis(){
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(a[i]>a[j])dp[i]=max(dp[i],dp[j]+1);
		}
	}
    return;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) {
		cin>>a[i];
    }
    lis();
    int ans=0;
    for(int i=1;i<=n;i++) {
  		ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
