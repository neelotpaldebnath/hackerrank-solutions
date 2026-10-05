// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/game-with-cells/problem?isFullScreen=true
// Problem     Army Game
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-05, 10:49 p.m.
// Technique   integer-division-grid-tiling
// Time        O(1)
// Space       O(1)
// Insight     The minimum number of packages required is calculated by tiling the grid with 2x2 blocks, where each dimension is effectively rounded up to the nearest even number by adding one before integer division.
// Interview   Before: "How would you approach covering an n by m grid with 2x2 squares?" After: "Since each 2x2 block covers four cells, we can compute the result in O(1) time using the formula ((n+1)/2) * ((m+1)/2), which correctly handles odd dimensions by accounting for the remaining border cells."
// Pitfalls    (1) Failing to account for odd-numbered dimensions, which require an extra package to cover the remaining row or column.  (2) Using floating-point division instead of integer division, which would lead to incorrect results for odd inputs.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    cout << ((n + 1) / 2) * ((m + 1) / 2);

    return 0;
}
