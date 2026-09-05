#include<bits/stdc++.h>
#define max_n 10005
using namespace std;
int size,a[max_n];
bool cmp(int num1,int num2){
	 return num1>num2;
}
void Selection_Sort(){
	for(int i=1;i<size;i++){
		int index=i+1;
		for(int j=i+1;j<=size;j++){
			if(cmp(a[index],a[j])){
				index=j;
			}
		}
		swap(a[index],a[i]);
	}
}
int main(){
	cin>>size;
	for(int i=1;i<=size;i++){
		cin>>a[i];
	}
	SelectionSort();
	for(int i=1;i<=size;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
