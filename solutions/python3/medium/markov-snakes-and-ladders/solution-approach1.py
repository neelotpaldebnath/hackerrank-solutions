# ──────────────────────────────────────────────────
# Link        https://www.hackerrank.com/challenges/markov-snakes-and-ladders/problem?isFullScreen=true
# Problem     Markov's Snakes And Ladders
# Difficulty  Medium
# Subdomain   Statistics and Machine Learning
# Platform    HackerRank
# Language    python3
# Status      Accepted
# Submitted   2026-09-28, 02:05 p.m.
# ──────────────────────────────────────────────────

import sys

def parse_pairs(line):
    line = line.strip()
    if not line:
        return []
    return [tuple(map(int, x.split(','))) for x in line.split()]

def solve(prob, ladders, snakes):
    board = list(range(101))

    for a, b in ladders:
        board[a] = b

    for a, b in snakes:
        board[a] = b

    dist = [0.0] * 101
    dist[1] = 1.0

    finished_probability = 0.0
    weighted_rolls = 0.0

    for roll in range(1, 1001):
        new_dist = [0.0] * 101

        for pos in range(1, 100):
            current = dist[pos]

            if current == 0.0:
                continue

            for face in range(1, 7):
                p = prob[face - 1]

                if p == 0.0:
                    continue

                nxt = pos + face

                if nxt > 100:
                    nxt = pos
                else:
                    nxt = board[nxt]

                amount = current * p

                if nxt == 100:
                    finished_probability += amount
                    weighted_rolls += amount * roll
                else:
                    new_dist[nxt] += amount

        dist = new_dist

    if finished_probability == 0.0:
        return 0

    return int(weighted_rolls / finished_probability + 0.5)

def main():
    input = sys.stdin.buffer.readline

    t = int(input())
    answers = []

    for _ in range(t):
        prob = list(map(float, input().decode().strip().split(',')))

        l, s = map(int, input().decode().strip().split(','))

        ladders = parse_pairs(input().decode())
        snakes = parse_pairs(input().decode())

        answers.append(str(solve(prob, ladders, snakes)))

    sys.stdout.write('\n'.join(answers))

if __name__ == "__main__":
    main()
