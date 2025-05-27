class Solution {
public:
    int trap(vector<int>& height) {


        // Method - 2 Time O(n), Space O(1)

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
    
        
        



        // Method - 1 Time O(n), Space O(n)
        // int n = height.size();
        // int res = 0;
        // vector<int> leftMax(n);
        // vector<int> rightMax(n);

        // leftMax[0] = height[0];
        // for(int i = 1; i < n; i++) {
        //     leftMax[i] = max(leftMax[i - 1], height[i]);
        // }

        // rightMax[n - 1] = height[n - 1];

        // for(int i = n - 2; i >= 0; i--) {
        //     rightMax[i] = max(rightMax[i + 1], height[i]);
        // }

        // for(int i = 1; i < n - 1; i++) {
        //     res += min(leftMax[i], rightMax[i]) - height[i];
        // }



        // return res;
    }
};