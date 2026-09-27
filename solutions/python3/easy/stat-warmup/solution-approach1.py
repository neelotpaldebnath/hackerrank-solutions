# ──────────────────────────────────────────────────
# Link        https://www.hackerrank.com/challenges/stat-warmup/problem?isFullScreen=true
# Problem     Basic Statistics Warmup
# Difficulty  Easy
# Subdomain   Statistics and Machine Learning
# Platform    HackerRank
# Language    python3
# Status      Accepted
# Submitted   2026-09-27, 06:57 p.m.
# ──────────────────────────────────────────────────

import math
from collections import Counter

n = int(input())
arr = list(map(int, input().split()))

mean = sum(arr) / n

arr.sort()

if n % 2 == 1:
    median = arr[n // 2]
else:
    median = (arr[n // 2 - 1] + arr[n // 2]) / 2

freq = Counter(arr)
max_freq = max(freq.values())
mode = min(x for x in freq if freq[x] == max_freq)

variance = sum((x - mean) ** 2 for x in arr) / n
sd = math.sqrt(variance)

margin = 1.96 * sd / math.sqrt(n)
lower = mean - margin
upper = mean + margin

print(f"{mean:.1f}")
print(f"{median:.1f}")
print(mode)
print(f"{sd:.1f}")
print(f"{lower:.1f} {upper:.1f}")
