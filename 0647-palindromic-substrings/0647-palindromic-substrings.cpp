class Solution {
public:
    int countSubstrings(string s) {
        int size  = s.size();
        int count = 0;

        for (int i = 0; i < size; i++) {
            count += Palindromes(s, i, i);
            count += Palindromes(s, i, i + 1);
        }

        return count;
        
    }

    int Palindromes(string& s, int l, int r) {
        int res = 0;
        int size = s.size();

        while (l >= 0 && r < size && s[l] == s[r]) {
            res++;
            l--;
            r++;
        }

        return res;
    }
};