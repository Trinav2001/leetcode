class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Method - 2
        int rows = matrix.size();
        int columns = matrix[0].size();
        int top = 0;
        int bottom = rows - 1;

        while(top <= bottom) {
            int r = (top + bottom) / 2;
            if(target > matrix[r][columns - 1]) {
                top = r + 1;
            }
            else if(target < matrix[r][0]) {
                bottom = r - 1;
            }
            else break;
        }

        if(top > bottom) return false;

        int r = (top + bottom) / 2;
        int l = 0;
        int h = columns - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(target > matrix[r][mid]) {
                l = mid + 1;
            }
            else if(target < matrix[r][mid]) {
                h = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;

        // Method - 1
        // vector<int> arr;

        // for(auto& row : matrix) {
        //     for(auto& val : row) {
        //         arr.push_back(val);
        //     }
        // }

        // int l = 0;
        // int h = arr.size() - 1;

        // while(l <= h) {
        //     int mid = l + (h - l) / 2;
        //     if(arr[mid] < target) l = mid + 1;
        //     else if(arr[mid] > target) h = mid - 1;
        //     else return true;
        // }
        // return false;
    }
};