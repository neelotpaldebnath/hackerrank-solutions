// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/summing-the-n-series/problem?isFullScreen=true
// Problem     Summing the N series 
// Difficulty  Medium
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-06, 09:55 p.m.
// Technique   mathematical-simplification-modulo
// Time        O(1)
// Space       O(1)
// Insight     The series simplifies to the sum of telescoping terms, resulting in the identity Sn = n^2, which is then computed modulo 10^9+7.
// Interview   Before: "I would iterate from 1 to n and sum the squares." After: "Since the series telescopes to n^2, I can compute the result in O(1) time by squaring n modulo 10^9+7, which handles the large constraints efficiently."
// Pitfalls    (1) Failing to apply the modulo operator to n before squaring can cause integer overflow for large n values.  (2) Neglecting to use long long for intermediate calculations will result in overflow before the modulo operation is applied.
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
