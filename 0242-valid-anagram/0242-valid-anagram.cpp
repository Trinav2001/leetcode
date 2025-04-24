class Solution {
public:
    bool isAnagram(string s, string t) {
        // Method 2
        if(s.length() != t.length()) {
            return false;
        }
        int count[26] = {0};
        for(auto c : s) {
            count[c - 'a']++;
        }
        
        for(auto c : t) {
            count[c - 'a']--;
        }

        for(auto i : count) {
            if(i != 0) {
                return false;
            }
        }
        return true;

        // Method 1
        // unordered_map<char, int> m;
        // for(auto c : s) {
        //     m[c]++;
        // }
        // for(auto c : t) {
        //     m[c]--;
        // }
        // for(auto& key : m) {
        //     if(key.second != 0) {
        //         return false;
        //     }
        // }
        // return true;
    }
};