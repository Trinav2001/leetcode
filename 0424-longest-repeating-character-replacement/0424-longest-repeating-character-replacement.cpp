class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int maxCount = 0;
        int left = 0;
        unordered_map<char, int> count;
        int right;
        for(right = 0; right < s.length(); right++) {
            count[s[right]]++;
            maxCount = max(maxCount, count[s[right]]);
            
            if((right - left + 1) - maxCount > k) {
                count[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);


        }
        return res;
    }
};