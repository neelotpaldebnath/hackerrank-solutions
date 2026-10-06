// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/p1-paper-cutting/problem?isFullScreen=true
// Problem     Cutting Paper Squares
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-06, 09:54 p.m.
// Technique   mathematical-formula-derivation
// Time        O(1)
// Space       O(1)
// Insight     The total number of cuts required to divide an n by m grid into unit squares is always n times m minus one, regardless of the order of cuts.
// Interview   Before: "I would simulate the cutting process using a recursive approach or a queue to track pieces." After: "Since each cut increases the total number of pieces by exactly one, the result is simply n times m minus one, which runs in O(1) time and O(1) space."
// Pitfalls    (1) Failing to use long long for the product of n and m, which may cause integer overflow for large inputs.  (2) Assuming the order of cuts affects the final count, ignoring the invariant that each cut adds exactly one piece.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    cout << n * m - 1 << '\n';

    return 0;
}
