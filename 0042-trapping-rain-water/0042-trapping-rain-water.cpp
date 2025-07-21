class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int res = 0;
        while(left < right) {
            if(leftMax <= rightMax) {
                left++;
                int water = leftMax - height[left];
                if(water > 0) {
                    res += water;
                }
                if(height[left] > leftMax) {
                    leftMax = height[left];
                }
            }
            else {
                    
                int water = rightMax - height[right];
                right--;
                if(water > 0) {
                    res += water;
                }
                    
                if(height[right] > rightMax) {
                    rightMax = height[right];
                }
            }
        }
        return res;
    }
};