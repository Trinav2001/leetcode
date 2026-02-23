class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string word = "";

        int len1 = word1.length();
        int len2 = word2.length();

        int i = 0;
        int j = 0;

        while (i < len1 || j < len2) {
            if (i < len1) {
                word += word1[i];
                i++;
            }
            
            if (j < len2) {
                word += word2[j];
                j++;
            }
            
        }

        return word;






        
    }
};