// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/strange-grid/problem?isFullScreen=true
// Problem     Strange Grid Again
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-08, 09:56 p.m.
// Technique   arithmetic-row-column-mapping
// Time        O(1)
// Space       O(1)
// Insight     The grid pattern repeats every two rows, where even-indexed rows (1-based) start with even numbers and odd-indexed rows start with odd numbers, allowing calculation via row-based offsets and column-based increments.
// Interview   Before: "I should simulate the grid using a 2D array to find the value at (r, c)." After: "Since the grid is infinite, I derived an O(1) formula using row parity and column offsets, ensuring the solution handles large row indices efficiently without memory overhead."
// Pitfalls    (1) Using 32-bit integers for the row index r, which can exceed the range of int given the infinite grid constraint.  (2) Incorrectly calculating the base value for odd versus even rows by failing to account for the (r-1) % 2 parity shift.  (3) Applying 0-based indexing to the input r and c without adjusting them to match the 1-based problem statement.
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
