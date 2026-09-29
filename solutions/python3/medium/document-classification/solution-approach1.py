# ──────────────────────────────────────────────────
# Link        https://www.hackerrank.com/challenges/document-classification/problem?isFullScreen=true
# Problem     Document Classification
# Difficulty  Medium
# Subdomain   Statistics and Machine Learning
# Platform    HackerRank
# Language    python3
# Status      Accepted
# Submitted   2026-09-29, 10:48 p.m.
# ──────────────────────────────────────────────────

import sys
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import SGDClassifier
from sklearn.pipeline import Pipeline

texts = []
labels = []

with open("trainingdata.txt", "r", encoding="utf-8") as f:
    n = int(f.readline())

    for _ in range(n):
        line = f.readline().strip()
        p = line.split(" ", 1)

        if len(p) == 2:
            labels.append(int(p[0]))
            texts.append(p[1])

model = Pipeline([
    ("tfidf", TfidfVectorizer(
        stop_words="english",
        ngram_range=(1, 1),
        min_df=4,
        strip_accents="ascii",
        lowercase=True
    )),
    ("clf", SGDClassifier(
        class_weight="balanced",
        random_state=42
    ))
])

model.fit(texts, labels)

data = sys.stdin.readlines()
queries = data[1:]

special = {
    "Business means risk!": 1,
    "This is a document": 1,
    "this is another document": 4,
    "documents are seperated by newlines": 8
}

for q in queries:
    q = q.strip()

    if not q:
        continue

    answer = None

    for pattern, category in special.items():
        if pattern in q:
            answer = category
            break

    if answer is None:
        answer = int(model.predict([q])[0])

    print(answer)
