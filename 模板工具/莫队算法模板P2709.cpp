#include <bits/stdc++.h>
#define int long long  // 定义int为long long，避免求和时溢出
using namespace std;

const int MAXN = 5e4 + 5;  // 数组最大容量，适配题目数据范围

// 全局变量定义
int n, m, k;               // n：数组长度，m：查询次数，k：题目中未使用（保留）
int a[MAXN];               // 原数组，存储输入的数列
int cnt[MAXN];             // 计数数组，cnt[x]表示当前区间内数字x出现的次数
int ans[MAXN];             // 答案数组，按查询的原始顺序存储结果
int cur;                   // 当前区间的答案（本题为「数字出现次数的平方和」）

// 查询结构体：存储每个查询的信息
struct Node {
    int lt, rt, id;  // lt：查询左端点，rt：查询右端点，id：查询的原始编号（用于还原答案顺序）
} q[MAXN];

int block;  // 分块的块大小，通常设为sqrt(n)

// 莫队算法的核心排序规则（奇偶优化版）
bool cmp(Node a, Node b) {
    // 第一步：按左端点所在块的编号升序排序（减少块间跳跃）
    if (a.lt / block != b.lt / block)
        return a.lt / block < b.lt / block;
    // 第二步：奇偶优化（减少右端点指针移动次数）
    // 奇数块：右端点降序；偶数块：右端点升序
    if ((a.lt / block) & 1)
        return a.rt > b.rt;
    return a.rt < b.rt;
}

// 向当前区间添加位置pos的元素（核心操作）
void add(int pos) {
    int x = a[pos];  // 获取pos位置的数值
    // 先减去x原来的贡献（平方项），再更新计数，最后加上新的贡献
    // 原理：sum = ... + cnt[x]^2 + ... → 删除旧项 → cnt[x]++ → 新增cnt[x]^2
    cur -= cnt[x] * cnt[x];
    cnt[x]++;                // x的出现次数+1
    cur += cnt[x] * cnt[x];  // 累加新的平方项到当前答案
}

// 从当前区间删除位置pos的元素（核心操作，与add对称）
void del(int pos) {
    int x = a[pos];  // 获取pos位置的数值
    // 先减去x原来的贡献，再更新计数，最后加上新的贡献
    cur -= cnt[x] * cnt[x];
    cnt[x]--;                // x的出现次数-1
    cur += cnt[x] * cnt[x];  // 累加新的平方项到当前答案
}

signed main() {
    // 关闭同步流+解绑cin，加速输入输出（处理大数据量必备）
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;          // 输入数组长度n、查询次数m、参数k（本题未用）
    block = sqrt(n);             // 块大小设为√n（莫队算法的最优块大小）
    
    // 输入原始数组
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // 输入m个查询，记录每个查询的左右端点和原始编号
    for (int i = 0; i < m; i++) {
        cin >> q[i].lt >> q[i].rt;
        q[i].id = i;  // 保存原始编号，避免排序后答案顺序混乱
    }
    
    // 对查询进行排序（莫队算法的核心步骤，减少指针移动次数）
    sort(q, q + m, cmp);
    
    // 初始化莫队指针：当前区间为 [1, 0]（空区间）
    int lt = 1, rt = 0;
    cur = 0;  // 初始答案为0（空区间无元素）
    
    // 处理每个查询（通过移动指针扩展/收缩区间，得到当前查询的答案）
    for (int i = 0; i < m; i++) {
        int ql = q[i].lt, qr = q[i].rt;  // 当前查询的左右端点
        
        // 扩展左指针：如果当前左指针 > 查询左端点，向左移动并添加元素
        while (lt > ql) add(--lt);
        // 扩展右指针：如果当前右指针 < 查询右端点，向右移动并添加元素
        while (rt < qr) add(++rt);
        // 收缩左指针：如果当前左指针 < 查询左端点，向右移动并删除元素
        while (lt < ql) del(lt++);
        // 收缩右指针：如果当前右指针 > 查询右端点，向左移动并删除元素
        while (rt > qr) del(rt--);
        
        // 将当前区间的答案存入ans数组（按查询原始编号存储）
        ans[q[i].id] = cur;
    }
    
    // 按查询的原始顺序输出答案
    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}
