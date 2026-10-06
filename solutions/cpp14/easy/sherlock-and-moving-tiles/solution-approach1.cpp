// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/sherlock-and-moving-tiles/problem?isFullScreen=true
// Problem     Sherlock and Moving Tiles
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-06, 09:58 p.m.
// Technique   algebraic-geometric-derivation
// Time        O(q)
// Space       O(q)
// Insight     The overlapping area of two squares moving along the diagonal y=x is a square whose side length decreases linearly over time based on the relative velocity of the two tiles.
// Interview   Before: "How do I simulate the movement of two squares to find the intersection area?" After: "Instead of simulation, derive the side length of the overlapping square as a function of time. This yields an O(q) solution using the relative velocity, avoiding complex geometric collision detection."
// Pitfalls    (1) Using integer division instead of floating-point division for the time calculation, which causes precision loss.  (2) Failing to use long double for intermediate calculations, leading to overflow or precision errors given the constraints up to 10^9.  (3) Neglecting the absolute value of the velocity difference, which is required since s1 and s2 can be provided in any order.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

vector<long double> movingTiles(long long l, long long s1, long long s2, const vector<long long>& queries) {
    vector<long double> ans;
    long double diff = fabsl((long double)s1 - (long double)s2);
    long double L = (long double)l;

    for (long long q : queries) {
        long double root = sqrtl((long double)q);
        long double gap = (L * L - (long double)q) / (L + root);
        long double time = sqrtl(2.0L) * gap / diff;
        ans.push_back(time);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, s1, s2;
    cin >> l >> s1 >> s2;

    int q;
    cin >> q;

    vector<long long> queries(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    vector<long double> ans = movingTiles(l, s1, s2, queries);

    cout << fixed << setprecision(4);

    for (long double x : ans) {
        cout << x << '\n';
    }

    return 0;
}
