# ──────────────────────────────────────────────────
# Link        https://www.hackerrank.com/challenges/markov-snakes-and-ladders/problem?isFullScreen=true
# Problem     Markov's Snakes And Ladders
# Difficulty  Medium
# Subdomain   Statistics and Machine Learning
# Platform    HackerRank
# Language    python3
# Status      Accepted
# Submitted   2026-09-28, 02:05 p.m.
# Technique   markov-chain-state-transition-simulation
# Time        O(T * R * S * D)
# Space       O(S)
# Insight     The algorithm computes the expected number of rolls by tracking the probability distribution of the player's position across the board over 1000 iterations.
# Interview   Before: "How would you simulate this game?" After: "I would use a Markov chain approach to track the probability of being on each square, resulting in O(T * R * S * D) time complexity, where R is 1000 rolls, S is 100 squares, and D is 6 die faces."
# Pitfalls    (1) Failing to handle the rule where rolls resulting in a square greater than 100 are wasted and the player remains at the original square.  (2) Incorrectly updating the board state by failing to apply ladder or snake transitions immediately upon landing on a square.  (3) Ignoring the requirement to normalize the expected value by the total probability of finishing within the 1000-roll limit.
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
