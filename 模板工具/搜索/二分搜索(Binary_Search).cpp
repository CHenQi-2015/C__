#include<bits/stdc++.h>
using namespace std;
int size,a[0x7fffffff],find;
int Binary_Search(){
	int l=1,r=size,mid;
	 while(l<=r){
		mid=l+(r-l)>>1;
		if(a[mid]==find){
			return mid;
		}else if(a[mid]<find){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return 0;
}
int main(){
	cin>>size>>find;
	for(int i=1;i<=size;i++){
		cin>>a[i];
	}
	sort(a+1,a+size+1)
	int BS=Binary_Search();
	if(BS){
		cout<<BS;
		return 0;
	}
	cout<<"No find";
	return 0;
}
