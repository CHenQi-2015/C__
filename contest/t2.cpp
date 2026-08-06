#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> leader(N);
    for (int i = 0; i < N; i++) cin >> leader[i];
    vector<int> votes(N + 1);
    for (int i = 1; i <= N; i++) cin >> votes[i];
    vector<int> leader_score(N + 1, 0);
    vector<pair<int, int>> vote_pairs;
    for (int i = 1; i <= N; i++) vote_pairs.push_back({votes[i], i});
    sort(vote_pairs.rbegin(), vote_pairs.rend());
    vector<int> other_score(N + 1, 0);
    for (int i = 0; i < N; i++) other_score[vote_pairs[i].second] = N - i;
    vector<tuple<int, int, int>> codes;
    for (int i = 1; i <= N; i++) {
        int total = leader_score[i] + other_score[i];
        codes.push_back({total, other_score[i], i});
    }
    sort(codes.begin(), codes.end(), [](const auto& a, const auto& b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
        return get<1>(a) > get<1>(b);
    });
    for (int i = 0; i < N; i++) {
        int total = get<0>(codes[i]);
        int label = get<2>(codes[i]);
        cout << (i + 1) << ". Kod";
        if (label < 10) cout << "0";
        cout << label << " (" << total << ")\n";
    }
    return 0;
}
