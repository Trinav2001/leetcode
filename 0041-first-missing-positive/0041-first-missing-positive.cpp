class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // Method - 2
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] > 0 && 
            nums[i] <= nums.size() && 
            nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else {
                i++;
            }
            
        }

        for(i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return i + 1;
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

        // Method - 1
        // unordered_map<int, int> count;
        // for(auto& num : nums) {
        //     count[num]++;
        // }
        // int max = *max_element(nums.begin(), nums.end());
        // int i;
        // for(i = 1; i <= max; i++) {
        //     if(count[i] == 0) {
        //         return i;
        //     }
        // }
        // return i;
};