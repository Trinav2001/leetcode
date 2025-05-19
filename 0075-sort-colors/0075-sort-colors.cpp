class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Method - 4
        int zero = 0;
        int one = 0; 
        int two = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                nums[two++] = 2;
                nums[one++] = 1;
                nums[zero++] = 0;
            }
            else if(nums[i] == 1) {
                nums[two++] = 2;
                nums[one++] = 1;
            }
            else {
                nums[two++] = 2;
            }
        }
        
        // Method - 3
        int left = 0; 
        int right = nums.size() - 1;
        int i = 0;

        while(i <= right) {
            if(nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
            }
            else if(nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
                i--;
            }
            i++;
        }

        // Method - 2
        // vector<int> count(3);
        // for(auto& val : nums) {
        //     count[val]++;
        // }
        // int index = 0;
        // for(int i = 0; i <= 2; ) {
        //     if(count[i] > 0) {
        //         nums[index++] = i;
        //         count[i]--;
        //     }
        //     else{
        //         i++;
        //     }
        // }
        
        // Method - 1
        // unordered_map<int, int> map;
        // for(auto& val : nums) {
        //     map[val]++;
        // }
        // vector<int> output(nums.size());
        // int index = 0;
        // for(int val = 0; val <= 2; ) {
        //     if (map[val] > 0) {
        //         output[index++] = val;
        //         --map[val];
        //     }
        //     else {
        //         val++;
        //     }
        // }
        
        // nums.clear();
        // for(auto& val : output) {
        //     nums.push_back(val);
        // }
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};