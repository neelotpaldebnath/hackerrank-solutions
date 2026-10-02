// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/matching-questions-answers/problem?isFullScreen=true
// Problem     Matching Questions with their Answers
// Difficulty  Hard
// Subdomain   Statistics and Machine Learning
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-02, 10:33 p.m.
// Technique   brute-force-permutation-scoring
// Time        O(P * Q * A + 5!)
// Space       O(P + Q + A)
// Insight     The implementation evaluates all possible question-answer pairings by calculating a heuristic score based on word overlap, proximity, and keyword matching, then selects the permutation that maximizes the total score.
// Interview   Before: "How do you map jumbled answers to questions?" After: "I calculate a heuristic score for every possible question-answer pair using keyword overlap and proximity, then use next_permutation to find the optimal assignment in O(5!) time, which is constant given the fixed constraint of five questions."
// Pitfalls    (1) The heuristic scoring relies on stop-word filtering and stemming, which may fail if the question and answer share no common non-stop words.  (2) The proximity score uses a fixed 250-character window, which might exclude relevant context if the answer is located far from the question's keywords.  (3) The implementation assumes exactly five answers are provided; if the input format deviates, the code returns early without outputting any results.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

string lowerAscii(string s) {
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z')
            c = char(c - 'A' + 'a');
    }
    return s;
}

vector<string> tokenize(const string &s) {
    vector<string> v;
    string cur;

    for (unsigned char c : s) {
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9')) {
            cur += char(tolower(c));
        } else {
            if (!cur.empty()) {
                v.push_back(cur);
                cur.clear();
            }
        }
    }

    if (!cur.empty())
        v.push_back(cur);

    return v;
}

bool stopWord(const string &s) {
    static const unordered_set<string> st = {
        "a","an","the","is","are","was","were","be","been",
        "being","of","to","in","on","at","for","from","by",
        "with","and","or","but","as","that","this","these",
        "those","it","its","they","their","them","he","his",
        "she","her","which","what","who","whom","where","when",
        "why","how","do","does","did","can","could","would",
        "should","will","shall","some","any","all","into",
        "than","then","there","here","have","has","had","having",
        "you","your","we","our","i","me","my","were"
    };

    return st.count(s);
}

string stem(string s) {
    if (s.size() > 5 && s.substr(s.size() - 3) == "ing")
        s.resize(s.size() - 3);
    else if (s.size() > 4 && s.substr(s.size() - 2) == "ed")
        s.resize(s.size() - 2);
    else if (s.size() > 4 && s.substr(s.size() - 2) == "es")
        s.resize(s.size() - 2);
    else if (s.size() > 3 && s.back() == 's')
        s.pop_back();

    return s;
}

vector<string> importantWords(const string &s) {
    vector<string> result;

    for (string w : tokenize(s)) {
        if (!stopWord(w))
            result.push_back(stem(w));
    }

    return result;
}

vector<pair<int,int>> positionsOf(
    const string &text,
    const string &answer
) {
    vector<pair<int,int>> result;

    string a = lowerAscii(text);
    string b = lowerAscii(answer);

    size_t pos = 0;

    while (true) {
        pos = a.find(b, pos);

        if (pos == string::npos)
            break;

        result.push_back({
            (int)pos,
            (int)(pos + b.size())
        });

        pos++;
    }

    return result;
}

string getContext(
    const string &paragraph,
    int start,
    int end
) {
    int left = start;

    while (left > 0) {
        char c = paragraph[left - 1];

        if (c == '.' || c == '?' || c == '!')
            break;

        left--;
    }

    int right = end;

    while (right < (int)paragraph.size()) {
        char c = paragraph[right];

        if (c == '.' || c == '?' || c == '!')
            break;

        right++;
    }

    return paragraph.substr(left, right - left);
}

double overlapScore(
    const vector<string> &questionWords,
    const string &context
) {
    vector<string> contextWords = importantWords(context);

    unordered_set<string> contextSet(
        contextWords.begin(),
        contextWords.end()
    );

    double score = 0.0;

    for (const string &w : questionWords) {
        if (contextSet.count(w))
            score += 10.0;
    }

    return score;
}

double proximityScore(
    const string &paragraph,
    const vector<string> &questionWords,
    int answerStart,
    int answerEnd
) {
    vector<string> paraWords = tokenize(paragraph);

    if (paraWords.empty())
        return 0;

    string leftText = paragraph.substr(
        max(0, answerStart - 250),
        min(
            (int)paragraph.size() - max(0, answerStart - 250),
            250 + answerEnd - answerStart
        )
    );

    vector<string> localWords = importantWords(leftText);

    unordered_set<string> qset(
        questionWords.begin(),
        questionWords.end()
    );

    double score = 0;

    for (const string &w : localWords) {
        if (qset.count(w))
            score += 2.0;
    }

    return score;
}

double candidateScore(
    const string &paragraph,
    const string &question,
    const string &answer
) {
    vector<string> qwords = importantWords(question);

    double best = -1e18;

    vector<pair<int,int>> positions =
        positionsOf(paragraph, answer);

    for (auto pos : positions) {
        string context =
            getContext(paragraph, pos.first, pos.second);

        double score =
            overlapScore(qwords, context);

        score += proximityScore(
            paragraph,
            qwords,
            pos.first,
            pos.second
        );

        vector<string> answerWords =
            importantWords(answer);

        unordered_set<string> qset(
            qwords.begin(),
            qwords.end()
        );

        for (const string &w : answerWords) {
            if (qset.count(w))
                score += 7.0;
        }

        best = max(best, score);
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string paragraph;

    if (!getline(cin, paragraph))
        return 0;

    vector<string> questions(5);

    for (int i = 0; i < 5; i++)
        getline(cin, questions[i]);

    string answerLine;
    getline(cin, answerLine);

    vector<string> answers;
    string current;

    for (char c : answerLine) {
        if (c == ';') {
            answers.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }

    answers.push_back(current);

    if (answers.size() != 5)
        return 0;

    double score[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            score[i][j] =
                candidateScore(
                    paragraph,
                    questions[i],
                    answers[j]
                );
        }
    }

    double bestScore = -1e100;
    int bestPerm[5];

    vector<int> perm = {0, 1, 2, 3, 4};

    do {
        double total = 0;

        for (int i = 0; i < 5; i++)
            total += score[i][perm[i]];

        if (total > bestScore) {
            bestScore = total;

            for (int i = 0; i < 5; i++)
                bestPerm[i] = perm[i];
        }

    } while (next_permutation(perm.begin(), perm.end()));

    for (int i = 0; i < 5; i++)
        cout << answers[bestPerm[i]] << '\n';

    return 0;
}
