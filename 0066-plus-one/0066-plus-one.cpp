class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int size = digits.size();


        int val = digits[size - 1] + 1;
        digits[size - 1] = val % 10;
        carry = val / 10;

        for (int i = size - 2; i >=0; i--) {
            val = digits[i] + carry;
            digits[i] = val % 10;
            carry = val / 10;
        }

        if (carry) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
        
        
    }
};