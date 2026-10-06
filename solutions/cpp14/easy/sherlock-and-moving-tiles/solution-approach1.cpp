// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/sherlock-and-moving-tiles/problem?isFullScreen=true
// Problem     Sherlock and Moving Tiles
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-06, 09:58 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

vector<long double> movingTiles(long long l, long long s1, long long s2, const vector<long long>& queries) {
    vector<long double> ans;
    long double diff = fabsl((long double)s1 - (long double)s2);
    long double L = (long double)l;

    for (long long q : queries) {
        long double root = sqrtl((long double)q);
        long double gap = (L * L - (long double)q) / (L + root);
        long double time = sqrtl(2.0L) * gap / diff;
        ans.push_back(time);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, s1, s2;
    cin >> l >> s1 >> s2;

    int q;
    cin >> q;

    vector<long long> queries(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    vector<long double> ans = movingTiles(l, s1, s2, queries);

    cout << fixed << setprecision(4);

    for (long double x : ans) {
        cout << x << '\n';
    }

    return 0;
}
