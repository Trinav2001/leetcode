class Solution {
public:
    bool isPalindrome(string s) {

        string Palindrome = "";

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (auto& c : s) {
            if (isalnum(c)) {
                Palindrome.push_back(c);
            }
        }

        int i = 0;
        int j = Palindrome.size() - 1;

        while (i < j) {
            if (Palindrome[i] != Palindrome[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;


        
    }
};