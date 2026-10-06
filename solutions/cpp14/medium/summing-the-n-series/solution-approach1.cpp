// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/summing-the-n-series/problem?isFullScreen=true
// Problem     Summing the N series 
// Difficulty  Medium
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-06, 09:55 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

long long summingSeries(long long n) {
    const long long MOD = 1000000007LL;
    n %= MOD;
    return (n * n) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        cout << summingSeries(n) << '\n';
    }

    return 0;
}
