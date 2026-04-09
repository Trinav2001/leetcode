class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int l = 0;
        int r = arr.size() - 1;
        int mid;

        while(l <= r) {
            mid = l + (r - l) / 2;
            int numberOfMissing = arr[mid] - (mid + 1);

            if (numberOfMissing < k) {
                l = mid + 1;
            }

            else {
                r = mid - 1;
            }
        }

        return l + k;  
    }
};