class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0;
        int idx = 0;

        int size = s.length();

        for (int i = 0; i < size; i++) {
            int l = i;
            int r = i;

            while (l >= 0 && r < size && s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    resLen = r - l + 1;
                    idx = l;
                }
                l--;
                r++;
            }  

            l = i;
            r = i + 1;

            while (l >= 0 && r < size && s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    resLen = r - l + 1;
                    idx = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(idx, resLen);
        
    }
};