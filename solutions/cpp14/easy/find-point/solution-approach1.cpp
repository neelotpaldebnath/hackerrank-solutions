// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/find-point/problem?isFullScreen=true
// Problem     Find the Point
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-08, 09:58 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

vector<int> findPoint(int px, int py, int qx, int qy) {
    return {2 * qx - px, 2 * qy - py};
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        vector<int> ans = findPoint(px, py, qx, qy);

        cout << ans[0] << " " << ans[1] << '\n';
    }

    return 0;
}
