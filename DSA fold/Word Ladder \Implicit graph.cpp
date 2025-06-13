class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_set<string> front{beginWord};
        unordered_set<string> back{endWord};
        int level = 1;

        while (!front.empty() && !back.empty()) {
            // Expand the smaller search front for optimization
            if (front.size() > back.size()) swap(front, back);

            unordered_set<string> nextLevel;
            for (const string& word : front) {
                string current = word;
                for (int i = 0; i < current.size(); ++i) {
                    char original = current[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        current[i] = ch;
                        if (back.count(current)) return level + 1;
                        if (dict.count(current)) {
                            nextLevel.insert(current);
                            dict.erase(current);
                        }
                    }
                    current[i] = original;
                }
            }
            front = move(nextLevel);
            ++level;
        }

        return 0;
    }
};
