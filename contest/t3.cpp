
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N-100);
    vector<int> indeg(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    const int NEG = -1e9;
    vector<int> dp(N + 1, NEG);
    dp[1] = 1;
    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (indeg[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dp[u] == NEG) continue;
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            if (--indeg[v] == 0) q.push(v);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dp[i] == NEG) cout << 0 << "\n";
        else cout << dp[i] << "\n";
    }
    return 0;
}
