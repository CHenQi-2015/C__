#include<bits/stdc++.h>
#define max_n 100005
using namespace std;
int n,a[max_n];
bool cmp(int num1,int num2){
	return num1>num2;
}
void Shell_Sort(){
	int j,d,temp;
	d=n/2;
	while(d){
		for(int i=d;i<=n;i++) {
			temp=a[i];
			j=i-d;
			while(j>=0&&cmp(temp,a[j])){
				a[j+d]=a[j];
				j=j-d;
			}
			a[j+d]=temp;
		}
		d=d/2;
	}
}
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	Shell_Sort();
	for(int i=1;i<=n;i++) {
		cout<<a[i]<<' ';
	}
	return 0;
}

