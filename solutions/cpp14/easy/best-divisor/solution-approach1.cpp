// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/best-divisor/problem?isFullScreen=true
// Problem     Best Divisor
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-07, 10:08 p.m.
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
