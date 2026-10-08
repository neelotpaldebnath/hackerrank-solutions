// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/diwali-lights/problem?isFullScreen=true
// Problem     Diwali Lights
// Difficulty  Medium
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-08, 09:57 p.m.
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
