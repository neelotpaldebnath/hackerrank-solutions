# ──────────────────────────────────────────────────
# Link        https://www.hackerrank.com/challenges/computing-the-correlation/problem?isFullScreen=true
# Problem     Day 5: Computing the Correlation
# Difficulty  Expert
# Subdomain   Statistics and Machine Learning
# Platform    HackerRank
# Language    python3
# Status      Accepted
# Submitted   2026-09-28, 02:01 p.m.
# Technique   single-pass-summation-formula
# Time        O(N)
# Space       O(1)
# Insight     The Pearson correlation coefficient is computed using the algebraic expansion of the covariance and standard deviations, allowing for a single-pass accumulation of necessary sums.
# Interview   Before: "How do I calculate correlation for 500,000 rows without storing them?" After: "By using the expanded formula for Pearson correlation, we maintain running sums of variables, squares, and products in O(N) time and O(1) space, avoiding memory overhead."
# Pitfalls    (1) Failure to handle the division by zero case when the variance of a subject is zero.  (2) Rounding errors when using floating-point arithmetic for large sums of squares.  (3) Incorrectly assuming the input format uses spaces instead of the specified tab-separated values.
# ──────────────────────────────────────────────────

import sys
import math

input = sys.stdin.buffer.readline

n = int(input())

sm = sp = sc = 0
sm2 = sp2 = sc2 = 0
smp = spc = smc = 0

for _ in range(n):
    m, p, c = map(int, input().split())

    sm += m
    sp += p
    sc += c

    sm2 += m * m
    sp2 += p * p
    sc2 += c * c

    smp += m * p
    spc += p * c
    smc += m * c

def correlation(sx, sy, sx2, sy2, sxy):
    num = n * sxy - sx * sy
    den_x = n * sx2 - sx * sx
    den_y = n * sy2 - sy * sy

    if den_x == 0 or den_y == 0:
        return 0.0

    return num / math.sqrt(den_x * den_y)

r_mp = correlation(sm, sp, sm2, sp2, smp)
r_pc = correlation(sp, sc, sp2, sc2, spc)
r_cm = correlation(sc, sm, sc2, sm2, smc)

print(f"{r_mp:.2f}")
print(f"{r_pc:.2f}")
print(f"{r_cm:.2f}")
