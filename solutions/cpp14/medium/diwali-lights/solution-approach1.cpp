// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/diwali-lights/problem?isFullScreen=true
// Problem     Diwali Lights
// Difficulty  Medium
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-08, 09:57 p.m.
// Technique   modular-exponentiation-loop
// Time        O(T * N)
// Space       O(1)
// Insight     The total number of patterns for N bulbs is 2^N minus the single case where all bulbs are off, calculated using modular arithmetic.
// Interview   Before: "How would you calculate the number of non-empty subsets of N bulbs?" After: "Since each bulb has two states, there are 2^N total combinations. Subtracting the empty set gives 2^N - 1. This implementation uses an O(T * N) loop to compute the result modulo 10^5."
// Pitfalls    (1) Failing to handle the modulo operation correctly when subtracting one, which requires adding the modulus before taking the remainder.  (2) Using an integer type that overflows before the modulo operation is applied during the multiplication steps.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long ans = 1;

        for (int i = 0; i < N; i++) {
            ans = (ans * 2) % 100000;
        }

        ans = (ans - 1 + 100000) % 100000;

        cout << ans << '\n';
    }

    return 0;
}
