class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        int left, right;
        for (int i = 0; i < n; i++) {
            

            count += Palindrome(s, i, i);

            count += Palindrome(s, i, i + 1);
        }

        return count;
    }

    int Palindrome (string& s, int left, int right) {
        int res = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            res++;
            left--;
            right++;
        }

        return res;
    }
};