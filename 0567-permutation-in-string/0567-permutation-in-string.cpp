class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> need(26, 0), window(26, 0);

        for (char c: s1) need[c - 'a']++;

        for (int i = 0; i < s1.size(); i++) window[s2[i] - 'a']++;

        if (window == need) return true;

        int n = s2.size();
        for(int r = s1.size(); r < n; r++) {
            window[s2[r] - 'a']++;

            int l = r - s1.size();

            window[s2[l] - 'a']--;

            if (window == need) return true;
        }

        return false;

        
    }
};