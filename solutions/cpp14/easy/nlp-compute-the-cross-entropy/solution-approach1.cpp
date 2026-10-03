// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/nlp-compute-the-cross-entropy/problem?isFullScreen=true
// Problem     Compute the Cross-Entropy
// Difficulty  Easy
// Subdomain   Natural Language Processing
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-03, 11:06 p.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    double perplexity = 170;
    double crossEntropy = log2(perplexity);

    cout << fixed << setprecision(2) << crossEntropy;

    return 0;
}
