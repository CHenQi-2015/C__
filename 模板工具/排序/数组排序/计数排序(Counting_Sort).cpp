#include<bits/stdc++.h>
#define maxn 10000005
using namespace std;
int size,a[maxn],max_v,cnt[max_n];
void Counting_Sort(){
	for(int i=1;i<=size;i++){
		max_v=max(max_v,a[i]);
		cnt[a[i]]++;
	}
}
int main(){
	cin>>size;
	for(int i=1;i<=size;i++){
		cin>>a;
	}
	Counting_Sort();
	for(int i=1;i<=max_v;i++){
		for(int j=1;j<=cnt[i];j++){
			cout<<i<<' ';
		}
	}
	return 0;
}
