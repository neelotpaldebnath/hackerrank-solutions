// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/leonardo-and-prime/problem?isFullScreen=true
// Problem     Leonardo's Prime Factors
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-05, 10:50 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int primeCount(long long n) {
    static vector<long long> primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59
    };

    __int128 product = 1;
    int count = 0;

    for (long long p : primes) {
        if (product * p > n)
            break;

        product *= p;
        count++;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        long long n;
        cin >> n;
        cout << primeCount(n) << '\n';
    }

    return 0;
}
