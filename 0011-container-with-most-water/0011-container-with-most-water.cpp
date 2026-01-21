class Solution {
public:
    int maxArea(vector<int>& height) {

        int l = 0;
        int r = height.size() - 1;

        int maxArea = -1;

        while (l < r) {
            int width = r - l;

            int length = min(height[l], height[r]);

            int curArea = width * length;

            maxArea = max(maxArea, curArea);

            if (height[l] < height[r]) {
                l++;
            }
            
            else {
                r--;
            }


        }

        return maxArea;
        
    }
};