// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/maximum-draws/problem?isFullScreen=true
// Problem     Maximum Draws
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-04, 10:27 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int maximumDraws(int n) {
    return n + 1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << maximumDraws(n) << '\n';
    }

    return 0;
}
