# ──────────────────────────────────────────────────
# Link        https://www.hackerrank.com/challenges/the-best-aptitude-test/problem?isFullScreen=true
# Problem     The Best Aptitude Test
# Difficulty  Medium
# Subdomain   Statistics and Machine Learning
# Platform    HackerRank
# Language    python3
# Status      Accepted
# Submitted   2026-09-29, 10:49 p.m.
# ──────────────────────────────────────────────────

import sys
import math

def ranks(values):
    n = len(values)
    order = sorted(range(n), key=lambda i: values[i])
    result = [0.0] * n
    i = 0

    while i < n:
        j = i
        while j + 1 < n and values[order[j + 1]] == values[order[i]]:
            j += 1

        rank = (i + j) / 2.0 + 1.0

        for k in range(i, j + 1):
            result[order[k]] = rank

        i = j + 1

    return result

def spearman(a, b):
    ra = ranks(a)
    rb = ranks(b)
    n = len(a)

    ma = sum(ra) / n
    mb = sum(rb) / n

    num = 0.0
    da = 0.0
    db = 0.0

    for i in range(n):
        x = ra[i] - ma
        y = rb[i] - mb
        num += x * y
        da += x * x
        db += y * y

    if da == 0 or db == 0:
        return 0.0

    return num / math.sqrt(da * db)

data = sys.stdin.buffer.read().split()
p = 0

t = int(data[p])
p += 1

answers = []

for _ in range(t):
    n = int(data[p])
    p += 1

    gpa = [float(data[p + i]) for i in range(n)]
    p += n

    tests = []

    for _ in range(5):
        scores = [float(data[p + i]) for i in range(n)]
        p += n
        tests.append(scores)

    best_test = 1
    best_corr = -float("inf")

    for i in range(5):
        corr = spearman(gpa, tests[i])

        if corr > best_corr:
            best_corr = corr
            best_test = i + 1

    answers.append(str(best_test))

print("\n".join(answers))
