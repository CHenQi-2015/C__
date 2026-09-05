#include<bits/stdc++.h>
#define max_n 10000000
using namespace std;
int n,a[max_n],dp[max_n],cnt;
void lis(){
	int t;
	for(int i=1;i<=n;i++) {
		cin>>t;
		if(t>dp[cnt]){
			cnt++;
			dp[cnt]=t;
		}else{
			int index=lower_bound(dp+1,dp+1+cnt,t)-dp;
			dp[index]=t;
		}
    }
    return;
}
int main(){
    cin>>n;
    lis();
    cout<<cnt;
    return 0;
}
