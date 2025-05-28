class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0;
        int result = 0;
        for(int right = 0; right < s.length(); right++) {
            while(set.count(s[right])) {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            result = max(result, right - left + 1);
        }
        return result;
    }
};