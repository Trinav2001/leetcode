class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr;

        for(auto& row : matrix) {
            for(auto& val : row) {
                arr.push_back(val);
            }
        }

        int l = 0;
        int h = arr.size() - 1;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(arr[mid] < target) l = mid + 1;
            else if(arr[mid] > target) h = mid - 1;
            else return true;
        }
        return false;
    }
};