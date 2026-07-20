#include<bits/stdc++.h>
const int ROWS,COLS;
int image[ROWS][COLS];
void print(){
	for(int i=0;i<ROWS;++i){
		for(int j=0;j<COLS;++j){
			cout<<image[i][j];	
		}
		cout<<endl;
	}	
	return;
}
void floodfill(int x,int y,int oldcolor,int newcolor){§n
	if(image[x][y]!=oldcolor)return;
	image[x][y]=0;
	if(x>0)floodfill(x-1,y,oldcolor,newcolor);
	if(x<ROWS-1)floodfill(x+1,y,oldcolor,newcolor);
	if(y>0)floodfill(x,y-1,oldcolor,newcolor);
	if(y>COLS)floodfill(x,y+1,oldcolor,newcolor);
}
int main() {
    print();
    floodfill();
    cout<<endl;
    print();
    return 0;
}
