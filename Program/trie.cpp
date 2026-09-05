#include <bits/stdc++.h>
using namespace std;

// 最大字符串长度 
const int N = 3e6 + 5;
// 字符集大小（大小写字母）
const int CHARSET = 65;
// 存储子节点编号，0表示不存在
int nxt[N][CHARSET];
// 经过该节点的字符串数
int cnt[N];
// 以该节点结尾的字符串数
int ed[N];
// 当前节点总数（0号节点为根）
int tot = 0;

// 将字符转换为数字
int get_num(char c) {
	if ((c >= 'a') && (c <= 'z')) return c - 'a' + 26;
	else if ((c >= 'A') && (c <= 'Z')) return c - 'A';
	else return c - '0' + 52;
}

// 插入
void insert(string s) {
	int len = s.length();
	
	// 从trie树的根开始遍历
	int p = 0;
	 
	// 依次遍历字符串的每个字符
	for (int i = 0; i < len; ++i) {
		int c = get_num(s[i]);
		if (!nxt[p][c]) {
			nxt[p][c] = ++tot;
		}
		
		p = nxt[p][c];
		cnt[p]++;
	} 
}

int find(string s) {
	int len = s.length();
	
	// 从trie树的根开始遍历
	int p = 0;
	
	// 依次遍历匹配串的每个字符
	for (int i = 0; i < len; ++i) {
		int c = get_num(s[i]);
		if (!nxt[p][c])
			return 0;
			
		p = nxt[p][c];
	}
	
	return cnt[p];
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0), std::cout.tie(0);
  	
	int T, n, q;
	cin >> T;
	
	while (T--) {
		for (int i = 0; i <= tot; ++i)
			for (int j = 0; j <= 65; ++j)
				nxt[i][j] = 0;
		for (int i = 0; i <= tot; ++i)
			cnt[i] = 0, ed[i] = 0;
		tot = 0;
		
		cin >> n >> q;
		string s;
		for (int i = 1; i <= n; ++i) {
			cin >> s;
			insert(s);
		}
		
		for (int i = 1; i <= q; ++i) {
			cin >> s;
			cout << find(s) << "\n";
		}
	}
	
	return 0;
}
