class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        int matches = 0;

        if(s1.length() > s2.length()) return false;

        for(int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(freq1[i] == freq2[i]) matches++;
        }

        int left = 0;
        int idx;
        for(int right = s1.size(); right < s2.size(); right++) {
            if(matches == 26) return true;

            idx = s2[right] - 'a';
            freq2[idx]++;
            if(freq1[idx] == freq2[idx]) matches++;
            else if(freq1[idx] + 1 == freq2[idx]) matches--;

            idx = s2[left] - 'a';
            freq2[idx]--;
            if(freq1[idx] == freq2[idx]) matches++;
            else if(freq1[idx] - 1 == freq2[idx]) matches--;
            left++;
        }
        return matches == 26;

    }
};