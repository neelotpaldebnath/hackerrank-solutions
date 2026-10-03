// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/the-trigram/problem?isFullScreen=true
// Problem     The Trigram
// Difficulty  Easy
// Subdomain   Natural Language Processing
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-03, 11:05 p.m.
// Technique   sentence-parsing-map-frequency
// Time        O(N)
// Space       O(N)
// Insight     The implementation processes the input by splitting text into sentences at each period, tokenizing words into lowercase, and tracking trigram frequencies while preserving the original insertion order to resolve ties.
// Interview   Before: "How do I handle trigrams spanning across sentence boundaries?" After: "The problem requires trigrams to exist within a single sentence, so I split the input by periods first. This O(N) approach ensures we only count valid trigrams while using a map and vector to maintain frequency and insertion order for O(N) time complexity."
// Pitfalls    (1) Failing to handle the case where a sentence ends with a period, which is correctly managed here by clearing the sentence buffer after processing.  (2) Incorrectly including words from different sentences in a trigram, which is prevented by resetting the word list at each period delimiter.  (3) Ignoring the requirement to output the first occurring trigram in case of ties, which is handled by iterating through the insertion-order vector.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, line;

    while (getline(cin, line)) {
        if (!text.empty())
            text += ' ';
        text += line;
    }

    map<string, int> freq;
    vector<string> order;

    string sentence;

    for (int i = 0; i <= (int)text.size(); i++) {
        if (i == (int)text.size() || text[i] == '.') {
            stringstream ss(sentence);
            vector<string> words;
            string word;

            while (ss >> word) {
                for (char& c : word)
                    c = tolower((unsigned char)c);

                words.push_back(word);
            }

            for (int j = 0; j + 2 < (int)words.size(); j++) {
                string tri = words[j] + " " + words[j + 1] + " " + words[j + 2];

                if (!freq.count(tri))
                    order.push_back(tri);

                freq[tri]++;
            }

            sentence.clear();
        } else {
            sentence += text[i];
        }
    }

    string answer;
    int best = 0;

    for (const string& tri : order) {
        if (freq[tri] > best) {
            best = freq[tri];
            answer = tri;
        }
    }

    cout << answer << '\n';

    return 0;
}
