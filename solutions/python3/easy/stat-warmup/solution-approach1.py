# ──────────────────────────────────────────────────
# Link        https://www.hackerrank.com/challenges/stat-warmup/problem?isFullScreen=true
# Problem     Basic Statistics Warmup
# Difficulty  Easy
# Subdomain   Statistics and Machine Learning
# Platform    HackerRank
# Language    python3
# Status      Accepted
# Submitted   2026-09-27, 06:57 p.m.
# Technique   sorting-and-frequency-counting
# Time        O(N log N)
# Space       O(N)
# Insight     The implementation calculates statistical metrics by sorting the array for median determination and using a hash map to identify the smallest mode among those with maximum frequency.
# Interview   Before: "How would you compute these statistics efficiently?" After: "I sort the array in O(N log N) time to find the median and use a hash map for O(N) mode identification, ensuring the standard deviation and confidence interval are calculated using the provided constant 1.96."
# Pitfalls    (1) Failing to select the numerically smallest integer when multiple elements share the maximum frequency as required by the mode definition.  (2) Incorrectly calculating the median for even-length arrays by not averaging the two middle elements.  (3) Using an incorrect constant for the 95% confidence interval instead of the specified 1.96.
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
