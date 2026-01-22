class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> set;
        int left = 0;
        int right;
        int maxLength = 0;

        for (right = 0; right < s.size(); right++) {
            
            while (set.count(s[right])) {
                set.erase(s[left]);
                left++;
            }

            set.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
        
    }
};