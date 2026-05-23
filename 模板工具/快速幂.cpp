#include<bits/stdc++.h>
using namespace std;
long long a,n,m;
long long Quick_power(){
	long long t=a,ans=1%m;
	while(n){
		if(n&1){
			ans=(ans*t)%m;
		}
		t=(t*t)%m;
		n>>=1;
	}
	return ans;
}
int main(){
	cin>>a>>n>>m;
	cout<<Quick_power();	
	return 0;
} 
