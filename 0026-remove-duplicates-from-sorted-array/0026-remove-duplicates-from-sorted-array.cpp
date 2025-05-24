class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // Method - 2
        int l = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                nums[l++] = nums[i];
            }
        }
        return l;

        // Method - 1
        // for(int i = 0; i < nums.size(); i++) {
        //     int j = i + 1;
        //     while(j < nums.size() && nums[j] == nums[i]) {
        //         j++;
        //     }
        //     nums.erase(nums.begin() + (i + 1), nums.begin() + j);
        // }
        // return nums.size();
    }
};