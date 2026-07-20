#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // 优化输入输出流速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<string> states(m);
    for (int i = 0; i < m; ++i) {
        cin >> states[i];
    }

    // t[i] 表示距离为 i 时的增加时间，使用 1-based 索引方便处理
    vector<long long> t(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    // 存储每只 T 狗的 (总耗时, 编号)
    vector<pair<long long, int>> dogs(m);

    for (int i = 0; i < m; ++i) {
        long long total_time = 0;
        int last_stumble = 0; // 初始位置为 0

        for (int j = 1; j <= n; ++j) {
            // 注意字符串是 0-based 索引
            if (states[i][j - 1] == '1') {
                int dist = j - last_stumble;
                // 最后一个障碍绊倒不增加时间
                if (j != n) {
                    total_time += t[dist];
                }
                last_stumble = j; // 更新上一次绊倒位置
            }
        }
        dogs[i] = {total_time, i + 1}; // 编号为 1 到 m
    }

    // 排序：第一关键字耗时升序，第二关键字编号升序
    sort(dogs.begin(), dogs.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int rank = 0;
    // 找到第 k 只 T 狗的名次
    for (int i = 0; i < m; ++i) {
        if (dogs[i].second == k) {
            rank = i + 1; // 数组索引 0 对应第 1 名
            break;
        }
    }

    cout << rank << "\n";

    return 0;
}
