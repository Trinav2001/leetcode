class Solution {
public:
    int mySqrt(int x) {
        // Method - 1
        // return sqrt(x);

        // Method - 2
        int left = 0;
        int res = 0;
        int right = x;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if((long long)mid * mid > x) {
                right = mid - 1;
            }

            else if((long long)mid * mid < x) {
                res = mid;
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return res;
    }
};