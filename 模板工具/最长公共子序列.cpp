#include<bits/stdc++.h>
using namespace std;
string s,t;
int l,vs[][];
int f(int i,int j){
	if(i>=l||j>=l)return 0;
	if(vs[i][j])return vs[i][j];
	if(s[i]==t[j])vs[i][j]=f(i+1,j+1)+1;
	else vs[i][j]=max(f(i+1,j),f(i,j+1));
	return vs[i][j];
}
int main(){
	cin>>;
	
	f(0,0);
	
	return 0;
}
