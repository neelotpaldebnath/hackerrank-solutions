// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/lowest-triangle/problem?isFullScreen=true
// Problem     Minimum Height Triangle
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-04, 10:29 p.m.
// Technique   integer-division-ceiling
// Time        O(1)
// Space       O(1)
// Insight     The minimum integer height is calculated by performing ceiling division of twice the area by the base using the formula (2 * a + b - 1) / b.
// Interview   Before: "How would you find the smallest integer height for a triangle with area at least a and base b?" After: "Since area = (base * height) / 2, we need height >= 2a / b. Using integer arithmetic, (2a + b - 1) / b provides the ceiling in O(1) time."
// Pitfalls    (1) Integer overflow occurs if 2 * a exceeds the maximum value of a 32-bit signed integer.  (2) The formula (2 * a + b - 1) / b assumes b is positive, which is guaranteed by the problem constraints.
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
