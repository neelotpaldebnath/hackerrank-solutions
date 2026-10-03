// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/the-trigram/problem?isFullScreen=true
// Problem     The Trigram
// Difficulty  Easy
// Subdomain   Natural Language Processing
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-10-03, 11:05 p.m.
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
