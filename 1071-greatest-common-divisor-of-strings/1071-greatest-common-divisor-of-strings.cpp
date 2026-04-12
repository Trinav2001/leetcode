class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        for (int i = min(len1, len2); i > 0; i--) {
            if (isDivisor(i, str1, str2)) {
                return str1.substr(0, i);
            }
        }

        return "";
        
    }

    bool isDivisor(int i, string str1, string str2) {
        if (str1.length() % i || str2.length() % i) {
            return false;
        }

        int len1 = str1.length() / i;
        int len2 = str2.length() / i;

        string sub = str1.substr(0, i);

        string s1 = "";
        string s2 = "";

        for (int j = 0; j < len1; j++) {
            s1 += sub;
        }

        for (int j = 0; j < len2; j++) {
            s2 += sub;
        }

        return s1 == str1 && s2 == str2;
    }
};