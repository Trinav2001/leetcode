class Solution {
public:
    int mySqrt(int x) {

        if (x <= 1) {
            return x;
        }

        int right = x / 2;
        int left = 0;
        int res = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if ((long)mid * mid <= x) {
                res = max (res, mid);
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return res;
        
    }
};