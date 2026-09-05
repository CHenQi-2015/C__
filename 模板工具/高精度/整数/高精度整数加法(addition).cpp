#include<iostream>
using namespace std;
const int N=10000;
int num1[N]={},num2[N]={},sum[N+1]={};
void addition(string n,string m){
	int len1=n.size(),len2=m.size();
	for(int i=0;i<len1;++i){
		num1[len1-1-i]=n[i]-48;
	}for(int i=0;i<len2;++i){
		num2[len2-1-i]=m[i]-48;
	}for(int i=0;i<max(len1,len2);++i){
		sum[i]=num1[i]+num2[i];
		sum[i+1]=sum[i]/10;
		sum[i]=sum[i]%10;
	}
	int rem=max(len1,len2)+1;
	if(sum[rem-1]==0&&rem>1){
		--rem;
	}
	return;
}
int main(){
	string n,m;
	cin>>n>>m;
	addtion(n,m);
	for(int i=0;i<rem;++i){
		cout<<sum[rem-1-i];
	}
	return 0;
}
