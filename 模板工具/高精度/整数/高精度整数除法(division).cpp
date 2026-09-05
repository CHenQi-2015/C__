#include<iostream>
using namespace std;
const int N=10000;
int num1[N],sum[N];
long long num2;
void division(string n,int m){
	int len1=n.size();
	for(int i=0;i<len1;++i){
		num1[i]=n[i]-48;
	}
	int res=0;
	for(int i=0;i<len;++i){
		sum[i]=(num1[i]+res*10)/num2;
		res=(num1[i]+res*10)%num2;
	}
	int rem=0;
	while(sum[rem-1]==0&&rem<len){
		++rem;
	}
}
int main(){
	string n,m;
	cin>>n>>m;
	division(n,m);
	for(int i=rem-1;i<len;++i){
		cout<<sum[i];
	}
	return 0;
}
