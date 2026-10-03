// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/nlp-compute-the-cross-entropy/problem?isFullScreen=true
// Problem     Compute the Cross-Entropy
// Difficulty  Easy
// Subdomain   Natural Language Processing
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-03, 11:06 p.m.
// Technique   log2-transformation
// Time        O(1)
// Space       O(1)
// Insight     The cross-entropy of a model is calculated as the base-2 logarithm of its perplexity.
// Interview   Before: "How do you derive cross-entropy from perplexity?" After: "Cross-entropy is the log2 of perplexity, resulting in O(1) time complexity for this calculation."
// Pitfalls    (1) Using the natural logarithm instead of the base-2 logarithm for perplexity conversion.  (2) Failing to format the output to exactly two decimal places as required by the problem statement.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    double perplexity = 170;
    double crossEntropy = log2(perplexity);

    cout << fixed << setprecision(2) << crossEntropy;

    return 0;
}
