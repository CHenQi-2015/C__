#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T, A, B;
    cin >> N >> T >> A >> B;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    const long long NEG = -(1LL << 60);
    vector<long long> f(T + 1, NEG);
    f[0] = 0;
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        vector<long long> nf(T + 1, NEG);
        for (int j = 0; j <= T; j++) {
            if (f[j] == NEG) continue;
            if (j + A <= T) nf[j + A] = max(nf[j + A], f[j] + a[i]);
            if (j + B <= T) nf[j + B] = max(nf[j + B], f[j]);
        }
        f = nf;
        for (int j = 0; j <= T; j++)
            if (f[j] != NEG) ans = max(ans, f[j]);
    }

    cout << ans << endl;
    return 0;
}
