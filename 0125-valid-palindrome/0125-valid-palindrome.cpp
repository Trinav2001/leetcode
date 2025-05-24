class Solution {
public:
    bool isPalindrome(string s) {
        string palindrome = "";
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i = 0; i < s.length(); i++) {
            if(isalnum(s[i])) {
                palindrome += s[i];
            }
        }
        int i, j;
        for(i = 0, j = palindrome.length() - 1; i < j; i++, j--) {
            if(palindrome[i] != palindrome[j]) {
                return false;
            }
        }
        return true;
    }
};