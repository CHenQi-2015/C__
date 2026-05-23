#include<bits/stdc++.h>
using namespace std;
int main(){
	system("echo on");
	system("g++ --version");
	string path;
	getline(cin,path);
	string cd="E:/mingw64/bin/g++.exe -fdiagnostics-color=always -g -static-libgcc -static-libg++\""+path+"\" -o \""+path.substr(0,path.size()-4)+".exe\"";
	system(cd.c_str());
	string open="start \""+path.substr(0,path.size()-4)+"\".exe";
	system(open.c_str());
	return 0;
}
