#define mid (l+r>>1)
struct xds {
	int n,a[N];
	struct stu {
		int l,r,add,num;
	} tr[4*N];
	void pushup(int k) {
		tr[k].num=tr[k<<1].num+tr[k<<1|1].num;
		return;
	}
	void pushdown(int k) {
		tr[k<<1].num+=tr[k].add*(tr[k<<1].r-tr[k<<1].l+1);
		tr[k<<1].add+=tr[k].add;
		tr[k<<1|1].num+=tr[k].add*(tr[k<<1|1].r-tr[k<<1|1].l+1);
		tr[k<<1|1].add+=tr[k].add;
		tr[k].add=0;
		return;
	}
	void build(int l,int r,int k) {
		tr[k]= {l,r,0,0};
		if(l==r)return tr[k].num=a[l],void();
		build(l,mid,k<<1);
		build(mid+1,r,k<<1|1);
		pushup(k);
		return;
	}
	void update(int ll,int rr,int k,int sum) {
		if(tr[k].r<ll||tr[k].l>rr)
			return;
		if(ll<=tr[k].l&&tr[k].r<=rr)return tr[k].add+=sum,
			                                   tr[k].num+=sum*(tr[k].r-tr[k].l+1),void();
		pushdown(k);
		update(ll,rr,k<<1,sum);
		update(ll,rr,k<<1|1,sum);
		pushup(k);
		return;
	}
	int query(int ll,int rr,int k) {
		if(tr[k].r<ll||tr[k].l>rr)return 0;
		if(ll<=tr[k].l&&tr[k].r<=rr)return tr[k].num;
		pushdown(k);
		int kkk=query(ll,rr,k<<1)+query(ll,rr,k<<1|1);
		pushup(k);
		return kkk;
	}
	void init(int x,int y[]) {
		n=x;
		for(int i=1; i<=x; i++)a[i]=y[i];
		build(1,n,1);
	}
};
#undef mid

//init(维护的数组大小，维护的数组) 初始化
//update(起点，终点，1，加的值) 修改
//query(起点，终点，1) 查询