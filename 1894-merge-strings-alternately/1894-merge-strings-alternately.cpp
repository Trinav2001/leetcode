class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string output = "";
        int i = 0;
        int j = 0;

        while(i < word1.length() || j < word2.length()) {
            if(i < word1.length()) {
                output += word1[i];
                i++;
            }

            if(j < word2.length()) {
                output += word2[j];
                j++;
            }
        }


        return output;
    }
};