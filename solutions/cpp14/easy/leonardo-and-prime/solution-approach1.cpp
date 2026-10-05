// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/leonardo-and-prime/problem?isFullScreen=true
// Problem     Leonardo's Prime Factors
// Difficulty  Easy
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-05, 10:50 p.m.
// Technique   greedy-prime-product-accumulation
// Time        O(Q * P) where P is the number of primes
// Space       O(P) for the static prime list
// Insight     The maximum number of distinct prime factors for any integer up to n is the largest count of consecutive primes whose product does not exceed n.
// Interview   Before: "I would iterate through all numbers up to n and factorize each one." After: "That is too slow for n up to 10^18. Instead, I greedily multiply the smallest primes until the product exceeds n, achieving O(Q * P) time complexity."
// Pitfalls    (1) Using a 64-bit integer for the product calculation will cause overflow for n near 10^18, requiring __int128.  (2) Failing to account for the constraint that 1 is not a prime number, which correctly results in a count of zero for n=1.  (3) Assuming the number of primes needed is large, when in fact the product of the first 15 primes already exceeds 10^18.
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
