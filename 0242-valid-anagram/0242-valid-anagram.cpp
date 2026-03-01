class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<int, int> count;
        

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (auto& pair : count) {
            if (count[pair.first] != 0) {
                return false;
            }
        }

        return true;

        
    }
};