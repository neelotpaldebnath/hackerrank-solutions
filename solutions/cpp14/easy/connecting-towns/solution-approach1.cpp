// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/connecting-towns/problem?isFullScreen=true
// Problem     Connecting Towns
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-05, 10:51 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int connectingTowns(int n, vector<int> routes) {
    const long long MOD = 1234567;
    long long ans = 1;

    for (int x : routes) {
        ans = (ans * x) % MOD;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> routes(n - 1);

        for (int &x : routes)
            cin >> x;

        cout << connectingTowns(n, routes) << '\n';
    }

    return 0;
}
