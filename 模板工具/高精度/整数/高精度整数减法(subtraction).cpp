#include<iostream>
using namespace std;
const int N=10000;
int num1[N]={},num2[N]={},sum[N]={};
int main(){
	string n,m;
	cin>>n;
	getchar();
	cin>>m;
	int len1=n.size(),len2=m.size();
	if(len1<len2||len1==len2&&n<m){
		cout<<'-';
		swap(n,m);
		swap(len1,len2);
	}
	for(int i=0;i<len1;++i){
		num1[len1-1-i]=n[i]-48;
	}for(int i=0;i<len2;++i){
		num2[len2-1-i]=m[i]-48;
	}for(int i=0;i<max(len1,len2);++i){
		if(num1[i]-num2[i]<0){
			--num1[i+1];
			num1[i]+=10;
		}
		sum[i]=num1[i]-num2[i];
	}
	int rem=max(len1,len2);
	while(sum[rem-1]==0&&rem>1){
		--rem;
	}
	for(int i=0;i<rem;++i){
		cout<<sum[rem-1-i];
	}
	return 0;
}
