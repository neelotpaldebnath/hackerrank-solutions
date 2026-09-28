# ──────────────────────────────────────────────────
# Link        https://www.hackerrank.com/challenges/computing-the-correlation/problem?isFullScreen=true
# Problem     Day 5: Computing the Correlation
# Difficulty  Expert
# Subdomain   Statistics and Machine Learning
# Platform    HackerRank
# Language    python3
# Status      Accepted
# Submitted   2026-09-28, 02:01 p.m.
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
