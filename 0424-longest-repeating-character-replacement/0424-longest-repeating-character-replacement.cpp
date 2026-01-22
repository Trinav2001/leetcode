class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> count;

        int left = 0;
        int right;
        int res = 0;

        for (right = 0; right < s.size(); right++) {
            count[s[right]]++;

            int maxCount = max(maxCount, count[s[right]]);

            if ((right - left + 1) - maxCount > k) {
                count[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
            
        }

        return res;
        
    }
};