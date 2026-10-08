// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/strange-grid/problem?isFullScreen=true
// Problem     Strange Grid Again
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-08, 09:56 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long r;
    int c;
    cin >> r >> c;

    long long ans = ((r - 1) / 2) * 10 + (r - 1) % 2 + 2 * (c - 1);

    cout << ans << '\n';

    return 0;
}
