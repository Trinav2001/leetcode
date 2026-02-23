class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> have(26, 0);
        vector<int> need(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            need[s1[i] - 'a']++;
        }

        for (int i = 0; i < s1.length(); i++) {
            have[s2[i] - 'a']++;
        }

        if (have == need) {
            return true;
        }

        int n = s2.size();
        int l = -1;

        for (int r = s1.size(); r < n; r++) {
            have[s2[r] - 'a']++;

            l++;

            have[s2[l] - 'a']--;

            if (have == need) {
                return true;
            }
        }

        return false;


        
    }
};