// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/find-point/problem?isFullScreen=true
// Problem     Find the Point
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-08, 09:58 p.m.
// Technique   midpoint-formula-inversion
// Time        O(n)
// Space       O(1)
// Insight     The reflected point r is calculated by applying the midpoint formula where q is the midpoint of segment pr, resulting in the coordinates rx = 2qx - px and ry = 2qy - py.
// Interview   Before: "How would you find the reflection of a point across another?" After: "Since the reflection point q is the midpoint of pr, we use the formula r = 2q - p. This approach runs in O(n) time for n queries with O(1) space per query."
// Pitfalls    (1) Integer overflow may occur if the coordinates px, py, qx, or qy are large enough that 2*qx or 2*qy exceeds the range of a 32-bit signed integer.  (2) Misinterpreting the point reflection formula by incorrectly subtracting the midpoint instead of doubling it.
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
