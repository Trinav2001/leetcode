class Solution {
public:
    string longestPalindrome(string s) {
        int resIndex;
        int resLength = 0;

        int n = s.length();
        int left, right;
        for (int i = 0; i < n; i++) {
            left = i;
            right = i;

            // Odd length
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > resLength) {
                    resIndex = left;
                    resLength = right - left + 1;
                }
                left--;
                right++;
            }


            left = i;
            right = i + 1;
            // Even length
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > resLength) {
                    resIndex = left;
                    resLength = right - left + 1;
                }
                left--;
                right++;
            }
        
        }

        return s.substr(resIndex, resLength);
    }
};