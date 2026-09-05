#include<bits/stdc++.h>
using namespace std;
int main(){
	system("echo off");
	while(1){
  		system("对拍测试值.exe>对拍测试.txt");
  		system("对拍测试.txt>对拍测试1.exe>1.txt");
  		system("对拍测试.txt>对拍测试2.exe>2.txt");
  		if(system("fc 1.txt 2.txt")){
			system("pause");
			return 0;
		}
	}
	return 0;
}