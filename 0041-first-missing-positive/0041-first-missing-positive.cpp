class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        

        // Method - 3 Negative indexing
        for(auto& num : nums) {
            if(num < 0) {
                num = 0;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]);
            if(val > 0 && val <= nums.size() && nums[val - 1] >= 0) {
                if(nums[val - 1] == 0) {
                    nums[val - 1] = -(nums.size() + 1);
                }
                else {
                    nums[val - 1] = -(nums[val - 1]);
                }
            }
        }


        int i;
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                return i + 1;
            }
        }

        return i + 1;
    }



        // Method - 2
    //     int i = 0;
    //     while(i < nums.size()) {
    //         if(nums[i] > 0 && 
    //         nums[i] <= nums.size() && 
    //         nums[i] != nums[nums[i] - 1]) {
    //             swap(nums[i], nums[nums[i] - 1]);
    //         }
    //         else {
    //             i++;
    //         }
            
    //     }

    //     for(i = 0; i < nums.size(); i++) {
    //         if(nums[i] != i + 1) {
    //             return i + 1;
    //         }
    //     }
    //     return i + 1;
    // }

    // void swap(int& a, int& b) {
    //     int temp = a;
    //     a = b;
    //     b = temp;
    // }

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