// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/reverse-game/problem?isFullScreen=true
// Problem     Reverse Game
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-07, 10:10 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        if (K < N / 2)
            cout << 2 * K + 1 << '\n';
        else
            cout << 2 * (N - 1 - K) << '\n';
    }

    return 0;
}
