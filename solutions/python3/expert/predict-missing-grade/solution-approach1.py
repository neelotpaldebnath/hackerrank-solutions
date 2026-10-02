# ──────────────────────────────────────────────────
# Link        https://www.hackerrank.com/challenges/predict-missing-grade/problem?isFullScreen=true
# Problem     Predict the Missing Grade
# Difficulty  Expert
# Subdomain   Statistics and Machine Learning
# Platform    HackerRank
# Language    python3
# Status      Accepted
# Submitted   2026-10-02, 10:34 p.m.
# Technique   ridge-regression-feature-engineering
# Time        O(N_train * M^2 + N_test * M)
# Space       O(N_train * M)
# Insight     The model maps sparse subject-grade inputs into a dense feature space using statistical aggregates and indicator flags to predict the missing Mathematics grade via ridge regression.
# Interview   Before: "How would you predict a missing categorical grade?" After: "I would use ridge regression on engineered features like subject means and indicator flags. This approach runs in O(N_train * M^2) time, where M is the number of subjects, effectively handling the 1-8 grade range with a tolerance of one point."
# Pitfalls    (1) Assuming all subjects are present in every record, which ignores the conditional logic for missing fields in the extract_features function.  (2) Failing to handle the input format correctly, specifically the initial integer N followed by N JSON lines.  (3) Neglecting the grade range constraint [1, 8] by failing to clip the regression output.
# ──────────────────────────────────────────────────

import json
import os
import sys
import numpy as np
from sklearn.linear_model import Ridge

# List of all non-Mathematics subjects in CBSE dataset
SUBJECTS = [
    'English', 'Physics', 'Chemistry', 'ComputerScience', 
    'Hindi', 'Biology', 'PhysicalEducation', 'Economics', 
    'Accountancy', 'BusinessStudies'
]

def extract_features(record):
    """Extract informative feature vector from student JSON record."""
    present_grades = []
    for sub in SUBJECTS:
        if sub in record and record[sub] is not None:
            present_grades.append(float(record[sub]))
            
    if present_grades:
        mean_g = sum(present_grades) / len(present_grades)
        min_g = min(present_grades)
        max_g = max(present_grades)
    else:
        mean_g, min_g, max_g = 4.5, 4.5, 4.5
        
    features = [mean_g, min_g, max_g, mean_g ** 2]
    
    # Subject-specific grade value and indicator flag
    for sub in SUBJECTS:
        if sub in record and record[sub] is not None:
            val = float(record[sub])
            features.append(val)
            features.append(1.0)
        else:
            features.append(mean_g)
            features.append(0.0)
            
    return features

def load_training_data():
    """Load training records from training.json or alternative candidate filenames."""
    X, y = [], []
    candidate_files = ['training.json', 'trainingdata.json', 'train.json']
    
    target_file = None
    for fname in candidate_files:
        if os.path.exists(fname):
            target_file = fname
            break

    if target_file:
        try:
            with open(target_file, 'r', encoding='utf-8') as f:
                content = f.read().strip()
                if content.startswith('['):
                    records = json.loads(content)
                else:
                    records = []
                    for line in content.splitlines():
                        line = line.strip()
                        if line:
                            try:
                                records.append(json.loads(line))
                            except Exception:
                                pass
                
                for r in records:
                    if isinstance(r, dict) and 'Mathematics' in r and r['Mathematics'] is not None:
                        X.append(extract_features(r))
                        y.append(float(r['Mathematics']))
        except Exception:
            pass

    return np.array(X), np.array(y)

def main():
    X_train, y_train = load_training_data()
    
    # Train Ridge Regression model if training data is available
    if len(X_train) > 0 and len(y_train) > 0:
        model = Ridge(alpha=10.0)
        model.fit(X_train, y_train)
    else:
        model = None

    # Read test input from STDIN
    raw_input = sys.stdin.read().splitlines()
    if not raw_input:
        return

    # Parse N from first line
    start_idx = 0
    N = 0
    for idx, line in enumerate(raw_input):
        line_str = line.strip()
        if line_str.isdigit():
            N = int(line_str)
            start_idx = idx + 1
            break

    test_lines = raw_input[start_idx:]
    if N > 0:
        test_lines = test_lines[:N]

    predictions = []
    for line in test_lines:
        line_str = line.strip()
        if not line_str:
            continue
        try:
            record = json.loads(line_str)
            feats = extract_features(record)
            
            if model is not None:
                pred_val = model.predict([feats])[0]
            else:
                # Fallback to mean grade of non-math subjects
                pred_val = feats[0]
                
            # Round and bound prediction within valid CBSE grade range [1, 8]
            pred_grade = int(np.clip(np.round(pred_val), 1, 8))
            predictions.append(str(pred_grade))
        except Exception:
            continue

    sys.stdout.write('\n'.join(predictions) + '\n')

if __name__ == '__main__':
    main()
