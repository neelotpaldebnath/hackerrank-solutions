// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/lowest-triangle/problem?isFullScreen=true
// Problem     Minimum Height Triangle
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-04, 10:29 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int lowestTriangle(int b, int a) {
    return (2 * a + b - 1) / b;
}

int main() {
    int b, a;
    cin >> b >> a;

    cout << lowestTriangle(b, a) << '\n';

    return 0;
}
