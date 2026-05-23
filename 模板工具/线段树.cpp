#include<bits/stdc++.h>
#define int long long
using namespace std;
const int max_n=1e5+5;
int tr[max_n<<2],tag[max_n<<2],n,m,a[max_n];
//构建线段树
void build(int r,int lt,int rt){
	//对 [lt,rt] 区间构建线段树,当前根的编号为 r
	if(lt==rt){
		tr[r]=a[lt];
		return;
	}
	int mid=((lt+rt)>>1);
	build(r<<1,lt,mid);
	build(r<<1|1,mid+1,rt);
	tr[r]=tr[r<<1]+tr[r<<1|1];//可替换
	return;
}
//向下传递懒标签，并更新数据
void push_down(int r,int lt,int rt){
	int mid=((lt+rt)>>1);
	tr[r<<1]=tr[r<<1]+(mid-lt+1)*tag[r];
	tag[r<<1]=tag[r<<1]+tag[r];
	tr[r<<1|1]=tr[r<<1|1]+(rt-(mid+1)+1)*tag[r];
	tag[r<<1|1]=tag[r<<1|1]+tag[r];
	tag[r]=0;
	return;
}
//区间修改
void update(int r,int lt,int rt,int qlt,int qrt,int v){
	if(qlt<=lt&&qrt>=rt){
		tr[r]=tr[r]+(rt-lt+1)*v/*可替换*/;
		tag[r]=tag[r]+v/*可替换*/;
	}
	push_down(r,lt,rt);
	int mid=((lt+rt)>>1);
	if(qlt>=lt&&qrt<=mid)update(r<<1,lt,mid,qlt,qrt,v);
	if(qlt>=mid+1&&qrt<=rt)update(r<<1|1,mid+1,rt,qlt,qrt,v);
	tr[r]=tr[r<<1]+tr[r<<1|1];
	return;
}
//区间查询
int query(int r,int lt,int rt,int qlt,int qrt){
	if(qlt>=rt&&qrt<lt)return 0;
	if(qlt<=lt&&qrt>=rt)return tr[r];
	push_down(r,lt,rt);
	int mid=((lt+rt)>>1);
	return query(r<<1,lt,mid,qlt,qrt)+query(r<<1,mid+1,rt,qlt,qrt);
}
//单点修改
void point_update(int r,int lt,int rt,int qpt,int v){
	if(lt>qpt||rt<qpt){
		return;
	}
	if(lt==rt){
		t[r]=t[r]+v/*可替换*/;
		return;
	}
	int mid=(lt+rt)/2;
	point_update(r<<1,lt,mid,qpt,v);
	point_update(r<<1|1,mid+1,rt,qpt,v);
	t[r]=t[r<<1]+t[r<<1|1];
	return;
}
//单点查询
int point_query(int r,int lt,int rt,int qpt){
	if(lt>qpt||rt<qpt){ 
		return 0;
	}
	if(lt==rt){
		return t[r];
	}
	int mid=(lt+rt)>>1;
	return point_query(r<<1,lt,mid,qpt)+point_query(r<<1|1,mid+1,rt,qpt);
}
signed main(){
	
	return 0;
}