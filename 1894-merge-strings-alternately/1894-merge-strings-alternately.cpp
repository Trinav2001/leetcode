class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string output = "";
        int i = 0;
        int j = 0;

        while(i < word1.length() && j < word2.length()) {
            if(i == j) {
                output += word1[i];
                i++;
            }
            else {
                output += word2[j];
                j++;
            }
        }

        for(; i < word1.length(); i++) {
            output += word1[i];
        }
        for(; j < word2.length(); j++) {
            output += word2[j];
        }

        return output;
    }
};