#include<stdio.h>
#define mn 100005
int t[mn],a[mn],n;
bool cmp(int num1,int num2){
	return num1>num2;
}
void Merge_Sort(int l,int r){
	if(l>=r)return;
	int mid=l+(r-l)/2;
	ms(l,mid);
	ms(mid+1,r);
	int pl=l,pr=mid+1,p=l;
	while((pl<=mid)&&(pr<=r)){
		if(cmp(a[pl],a[pr]))t[p++]=a[pl++];
		else t[p++]=a[pr++];
	}
	while(pl<=mid)t[p++]=a[pl++];
	while(pr<=r)t[p++]=a[pr++];
	for(int i=l;i<=r;i++)a[i]=t[i];
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	Merge_Sort(1,n);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}
