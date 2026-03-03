class Solution {
public:
    bool validPalindrome(string s) {

        return isPalindrome(s, 0, s.length() - 1);

        
    }

    bool isPalindrome(string s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return helper(s, left + 1, right) || helper(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }

    bool helper(string s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};