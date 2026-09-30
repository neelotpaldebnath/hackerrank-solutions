# ──────────────────────────────────────────────────
# Link        https://www.hackerrank.com/challenges/stack-exchange-question-classifier/problem?isFullScreen=true
# Problem     Stack Exchange Question Classifier
# Difficulty  Medium
# Subdomain   Statistics and Machine Learning
# Platform    HackerRank
# Language    python3
# Status      Accepted
# Submitted   2026-09-30, 11:26 p.m.
# Technique   tfidf-ridge-classifier-pipeline
# Time        O(N * L + M * L)
# Space       O(N * L + V)
# Insight     The model concatenates question titles and excerpts into a single feature string, then uses a TF-IDF vectorizer with bigrams and a Ridge classifier to map text to one of ten topics.
# Interview   Before: "How would you classify text into ten categories?" After: "I would use a TF-IDF vectorizer with n-grams to capture context, followed by a Ridge classifier for efficient multi-class prediction, achieving O(N*L) training time where N is the number of documents and L is the average document length."
# Pitfalls    (1) Failing to handle UTF-8 encoding in the input JSON objects can lead to decoding errors.  (2) Ignoring the requirement to read the training file from the local directory causes runtime failures.  (3) Using an insufficient number of features or incorrect n-gram ranges may result in poor classification accuracy.
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
