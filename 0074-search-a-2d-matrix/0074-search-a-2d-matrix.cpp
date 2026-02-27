class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = rows - 1;

        while (start <= end) {
            int midRow = start + (end - start) / 2;
            if (target < matrix[midRow][0]) {
                end = midRow - 1;
            }

            else if (target > matrix[midRow][cols - 1]) {
                start = midRow + 1;
            }

            else {
                int left = 0;
                int right = cols - 1;

                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    if (target < matrix[midRow][mid]) {
                        right = mid - 1;
                    }

                    else if (target > matrix[midRow][mid]) {
                        left = mid + 1;
                    }
                    else {
                        return true;
                   }
                }

                return false;
            }
        }

        return false;

        
    }
};
