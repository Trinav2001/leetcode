class Solution {
public:
    string convertToTitle(int columnNumber) {
        if (columnNumber == 0) {
            return "";
        }

        
        return convertToTitle((columnNumber - 1) / 26) + char('A' + (columnNumber - 1) % 26);

        
    }
};