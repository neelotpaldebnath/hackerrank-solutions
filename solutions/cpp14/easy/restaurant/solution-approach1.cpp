// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/restaurant/problem?isFullScreen=true
// Problem     Restaurant
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-07, 10:10 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int l, b;
        cin >> l >> b;

        int g = findGCD(l, b);

        cout << (l / g) * (b / g) << '\n';
    }

    return 0;
}
