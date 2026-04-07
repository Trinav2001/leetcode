class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> visit;

        while (!visit.contains(n)) {

            visit.insert(n);
            int sum = 0;
            int dividend = n;
            while (dividend) {
                int lastDigit = dividend % 10;
                sum += (lastDigit * lastDigit);
                dividend /= 10;
            }

            n = sum;

            if (n == 1) {
                return true;
            }            
        }

        return false;
        
    }
};