// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/handshake/problem?isFullScreen=true
// Problem     Handshake
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-04, 10:28 p.m.
// Technique   arithmetic-series-formula
// Time        O(1)
// Space       O(1)
// Insight     The total number of unique handshakes among n attendees is calculated using the combination formula n choose 2, which simplifies to n multiplied by n minus one divided by two.
// Interview   Before: "I would iterate through each person and count their unique handshakes with others." After: "Since every pair shakes hands exactly once, I can use the arithmetic series formula n(n-1)/2 to compute the result in O(1) time, which handles the constraint n < 10^6 efficiently."
// Pitfalls    (1) Using a 32-bit integer for the calculation can cause overflow when n is large, as n(n-1)/2 exceeds the capacity of a standard int.  (2) Failing to account for the case where n equals 1, which correctly results in 0 handshakes according to the formula.
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
