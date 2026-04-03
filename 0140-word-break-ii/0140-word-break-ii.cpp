class Solution {
private:
    unordered_set<string> wordSet;
    unordered_map<int, vector<string>> cache;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());

        return backtrack(s, 0);
        
    }

    vector<string> backtrack(string s, int i) {
        if (i == s.length()) {
            return {""};
        }

        if (cache.count(i)) {
            return cache[i];
        }

        vector<string> res;

        for (int j = i; j < s.length(); j++) {
            string word = s.substr(i, j - i + 1);

            if (!wordSet.count(word)) {
                continue;
            }

            vector<string> strs = backtrack(s, j + 1);

            for (const string& str : strs) {
                string subres = word;
                if (!str.empty()) {
                    subres += " " + str;
                }

                res.push_back(subres);

            }

        }

        cache[i] = res;
        return res;
    }
};