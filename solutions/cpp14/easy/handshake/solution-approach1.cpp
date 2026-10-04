// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/handshake/problem?isFullScreen=true
// Problem     Handshake
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-04, 10:28 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

long long handshakes(long long n) {
    return n * (n - 1) / 2;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        cout << handshakes(n) << '\n';
    }

    return 0;
}
