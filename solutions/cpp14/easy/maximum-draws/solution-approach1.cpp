// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/maximum-draws/problem?isFullScreen=true
// Problem     Maximum Draws
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-04, 10:27 p.m.
// Technique   pigeonhole-principle-formula
// Time        O(1)
// Space       O(1)
// Insight     The pigeonhole principle dictates that drawing n+1 socks from n distinct colors guarantees at least one matching pair.
// Interview   Before: "How would you calculate the worst-case scenario for matching socks?" After: "By applying the pigeonhole principle, we determine that n+1 draws are required to guarantee a match, resulting in O(1) time complexity for any n up to 10^6."
// Pitfalls    (1) Assuming the result is n instead of n+1, which fails the pigeonhole principle requirement for a guaranteed match.  (2) Neglecting the constraint that n is at least 1, though the formula n+1 holds for all positive integers.
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
