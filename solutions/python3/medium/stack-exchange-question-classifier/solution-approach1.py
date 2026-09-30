# ──────────────────────────────────────────────────
# Link        https://www.hackerrank.com/challenges/stack-exchange-question-classifier/problem?isFullScreen=true
# Problem     Stack Exchange Question Classifier
# Difficulty  Medium
# Subdomain   Statistics and Machine Learning
# Platform    HackerRank
# Language    python3
# Status      Accepted
# Submitted   2026-09-30, 11:26 p.m.
# ──────────────────────────────────────────────────

import json
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import RidgeClassifier
from sklearn.pipeline import Pipeline

pipeline = Pipeline([
    ("tfidf", TfidfVectorizer(
        sublinear_tf=True,
        max_features=150000,
        ngram_range=(1, 2),
        stop_words="english"
    )),
    ("clf", RidgeClassifier())
])

training_docs = []
training_labels = []

with open("training.json", "r", encoding="utf-8") as f:
    n = int(f.readline())

    for _ in range(n):
        obj = json.loads(f.readline())
        training_docs.append(
            obj["question"] + " " + obj["excerpt"]
        )
        training_labels.append(obj["topic"])

pipeline.fit(training_docs, training_labels)

n = int(input())

test_docs = []

for _ in range(n):
    obj = json.loads(input())
    test_docs.append(
        obj["question"] + " " + obj["excerpt"]
    )

predictions = pipeline.predict(test_docs)

for prediction in predictions:
    print(prediction)
