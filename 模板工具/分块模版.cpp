#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5 + 5;
// m = sqrt(n);
const int M = 1000;
// a: 原数组;
// id[i]: 原数组第i个数归属的块号 
// s: 每块的前缀和;
// tg: 每块的懒标签;
int a[N], id[N], s[M], tg[M];

int n, q, len;

// 添加 
// 单次操作的时间复杂度为: O(s) = O(sqrt(n)) 
void add(int lt, int rt, int v) {
	// 左右端点所在的块号 
	int lid = id[lt], rid = id[rt];
	
	// 如果在同一个块, 则处理块内的每个元素
	// 时间复杂度, 一块的元素数量: O(s) 
	if (lid == rid) {
		for (int i = lt; i <= rt; ++i) 
			a[i] += v, s[lid] += v;
			
		return;
	} 
	
	// 左边的不完整块的元素, 需要逐个修改块内的元素和前缀和 
	// 时间复杂度, 一块的元素数量: O(s) 
	for (int i = lt; id[i] == lid; ++i)
		a[i] += v, s[lid] += v;
		
	// 右边的不完整块的元素, 需要逐个修改块内的元素和前缀和 
	// 时间复杂度, 一块的元素数量: O(s) 
	for (int i = rt; id[i] == rid; --i)
		a[i] += v, s[rid] += v;
		
	// 中间成块, 直接计算整块的标签 和  前缀和
	// 时间复杂度, 遍历所涉及的所有的块: O(s) 
	for (int i = lid + 1; i < rid; ++i)
		// 懒标签
		tg[i] += v, s[i] += (v * len);
}

// 查询 
// 单次操作的时间复杂度为: O(s) = O(sqrt(n)) 
int qry(int lt, int rt, int v) {
	int ans = 0;
	
	// 左右端点所在的块号
	int lid = id[lt], rid = id[rt];
	
	// 如果在同一个块, 可能不是完整一块, 所以需要直接暴力求解块内的每个元素
	// 时间复杂度, 一块的元素数量: O(s) 
	if (lid == rid) {
		for (int i = lt; i <= rt; i++)
			ans += a[i] + tg[lid];
		
		int mod = v + 1;
		ans = (ans % mod + mod) % mod;
		
		return ans;
	}
	
	// 左边的不完整块的元素, 直接暴力求解
	// 时间复杂度, 一块的元素数量: O(s) 
	for (int i = lt; id[i] == lid; ++i)
		ans += a[i] + tg[lid];
	
	// 右边的不完整块的元素, 直接暴力求解
	// 时间复杂度, 一块的元素数量: O(s) 
	for (int i = rt; id[i] == rid; --i)
		ans += a[i] + tg[rid];
	
	// 中间成块, 只需加上整块的前缀和 
	// 时间复杂度, 遍历所涉及的所有的块: O(s) 
	for (int i = lid + 1; i < rid; ++i)
		ans += s[i];
	
	int mod = v + 1;
	ans = (ans % mod + mod) % mod;
	
	return ans;
}

signed main() {
	
	ios::sync_with_stdio(false);
    cin.tie(0);
	
	cin >> n;
	
	// 块的长度 
	len = sqrt(n);
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		
		// 第i个数所在的块的计算公式 
		id[i] = (i - 1) / len + 1;
		
		// 计算第i个块的前缀和 
		s[id[i]] += a[i];
	}
	
	int q = n, op, lt, rt, v;
	while (q--) {
		cin >> op >> lt >> rt >> v;
		
		if (op == 0)
			add(lt, rt, v);
		else {
			int ans = qry(lt, rt, v);
			cout << ans << endl;
		}
	}
	
	return 0;
} 
