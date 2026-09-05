#include<bits/stdc++.h>
using namespace std;
bool check(int n){
	
	return ;
}
int Binary_Search(){
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans; 
}
int main(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<Binary_Search();
	return 0;
} 
