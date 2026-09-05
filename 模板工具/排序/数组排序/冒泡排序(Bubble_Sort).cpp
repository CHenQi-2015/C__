#include<bits/stdc++.h>
#define max_n 100005
using namespace std;
int size,a[max_n];
bool cmp(int num1,int num2){
	return num1>num2;
}
void Bubble_Sort(){
	for(int i=1;i<=size;i++){
		for(int j=i;j<=size;j++){
			if(cmp(a[i],a[j])){
				swap(a[i],a[j]);
			}
		}
	}
}
int main(){
	cin>>size;
	for(int i=1;i<=size;i++){
		cin>>a[i];
	}
	Bubble_Sort();
	for(int i=1;i<=size;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
