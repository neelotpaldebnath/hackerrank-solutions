// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/sherlock-and-permutations/problem?isFullScreen=true
// Problem     Sherlock and Permutations
// Difficulty  Hard
// Subdomain   Fundamentals
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-09, 10:19 p.m.
// Technique   combinatorics-precomputed-factorials
// Time        O(MAXN + T)
// Space       O(MAXN)
// Insight     The number of unique permutations of N zeros and M ones starting with a one is equivalent to choosing the positions of the N zeros in the remaining N+M-1 slots.
// Interview   Before: "How would you count permutations with constraints?" After: "Fixing the first position as one leaves N zeros and M-1 ones to arrange in N+M-1 spots, calculated as (N+M-1) choose N in O(1) time after O(MAXN) precomputation."
// Pitfalls    (1) Failing to recognize that fixing the first digit reduces the problem to choosing N positions for zeros out of N+M-1 total remaining positions.  (2) Incorrectly applying the formula for permutations of a multiset without accounting for the fixed leading digit.  (3) Using modular inverse incorrectly when calculating combinations for large N and M values.
// ──────────────────────────────────────────────────


#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int MAXN = 2005;

long long fact[MAXN], invFact[MAXN];

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        cout << nCr(N + M - 1, N) << '\n';
    }

    return 0;
}
