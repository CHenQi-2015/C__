#include<bits/stdc++.h>
#define max_n 100005
using namespace std;
int n,a[max_n];
bool cmp(int num1,int num2){
	 return num1<num2;
}
void Quick_Sort(int lt,int rt){
	if(lt>=rt)return;
 	int k=lt,l=lt,r=rt;
	while(l<r){
		while(l<r&&a[r]>=a[k])--r;
		while(l<r&&a[l]<=a[k])++l;
		if(cmp(l,r))swap(a[l],a[r]);
	}
	int mid=l;
	swap(a[mid],a[k]);
	QuickSort(lt,mid-1);
	QuickSort(mid+1,rt);
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	Quick_Sort(1,n);
	for (int i=1;i<=n;i++){
		cout<<a[i]<<' ';

	}
	return 0;
}
