/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0;
        int r = mountainArr.length() - 1;
        int m;
        int peak = 0;
        while(l <= r) {
            m = (l + r) / 2;
            int left = (m - 1 >= 0) ? mountainArr.get(m - 1) : INT_MIN;
            int mid = mountainArr.get(m);
            int right = (m + 1 < mountainArr.length()) ? mountainArr.get(m + 1) : INT_MIN;

            if(left < mid && mid < right) l = m + 1;

            else if (left > mid && mid > right) r = m - 1;

            else break;
        }

        peak = m;
        if (mountainArr.get(peak) == target) return peak;

        l = 0;
        r = peak;
        while(l <= r) {
            int mid = (l + r) / 2;

            if(mountainArr.get(mid) > target) r = mid - 1;

            else if(mountainArr.get(mid) < target) l = mid + 1;

            else return mid;
        }


        l = peak;
        r = mountainArr.length() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;

            if(mountainArr.get(mid) > target) l = mid + 1;

            else if(mountainArr.get(mid) < target) r = mid - 1;

            else return mid;
        }

        return -1;
    }

    
};