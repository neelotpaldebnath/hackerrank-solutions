// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/best-divisor/problem?isFullScreen=true
// Problem     Best Divisor
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-07, 10:08 p.m.
// Technique   linear-scan-divisor-digit-sum
// Time        O(n log n)
// Space       O(1)
// Insight     The algorithm iterates through all integers up to n to identify divisors, tracking the one that maximizes the digit sum while using the smaller value as a tie-breaker.
// Interview   Before: "I could iterate through all numbers up to n and check if they divide n." After: "That works in O(n log n) time, where the log factor comes from the digit sum calculation. Since we need the best divisor based on digit sum and value, this linear scan is sufficient for the given constraints."
// Pitfalls    (1) Failing to handle the tie-breaking rule where the smaller number is preferred when digit sums are equal.  (2) Using an inefficient digit sum calculation that could impact performance for very large inputs.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int digitSum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    int best = 1;
    int bestSum = digitSum(1);

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            int sum = digitSum(i);

            if (sum > bestSum || (sum == bestSum && i < best)) {
                bestSum = sum;
                best = i;
            }
        }
    }

    cout << best << '\n';

    return 0;
}
