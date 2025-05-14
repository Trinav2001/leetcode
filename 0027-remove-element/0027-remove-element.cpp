class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        // Method - 2
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        return i;
        
        // Method - 1
        // for(int i = 0; i < nums.size(); i++) {
        //     if(nums[i] == val) {
        //         nums.erase(nums.begin() + i);
        //         --i;
        //     }
        // }
        // return nums.size();
    }
};