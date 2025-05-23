class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // Boyer-Moore Voting Algorithm using HashMap

        unordered_map<int, int> map;
        for(auto& num: nums) {
            map[num]++;
        }

        if(map.size() > 2) {
            unordered_map<int, int> temp;
            for(auto& pair : map) {
                if(pair.second > 1) {
                    temp[pair.first] = pair.second - 1;
                }
            }
            map = temp;
        }

        vector<int> output;
        for(auto& pair : map) {
            int frequency = 0;
            for(auto& num : nums) {
                if(num == pair.first) frequency++;
            }
            if(frequency > nums.size()/3) output.push_back(pair.first);
        }

        return output;




        // Boyer-Moore Voting Algorithm
        // int count1 = 0;
        // int count2 = 0;
        // int candidate1 = -1000000001;
        // int candidate2 = -1000000002;

        // vector<int> output;
        
        // for(auto& num : nums) {
        //     if(num == candidate1) {
        //         count1++;
        //     }
        //     else if(num == candidate2) {
        //         count2++;
        //     }
        //     else if(count1 == 0) {
        //         candidate1 = num;
        //         count1++;
        //     }
        //     else if(count2 == 0) {
        //         candidate2 = num;
        //         count2++;
        //     }
        //     else {
        //         count1--;
        //         count2--;
        //     }
        // }
        // count1 = 0;
        // count2 = 0;

        // for(auto& num : nums) {
        //     if(num == candidate1) count1++;
        //     if(num == candidate2) count2++;
        // }

        // if(count1 > nums.size()/3) output.push_back(candidate1);
        // if(count2 > nums.size()/3) output.push_back(candidate2);
        // return output;

        // Method - 1
        // unordered_map<int, int> map;
        // vector<int> output;
        // int n = nums.size();
        // int x = n / 3;
        // for(auto& num : nums) {
        //     map[num]++;
        // }

        // for(auto& pair : map) {
        //     if(pair.second > x) {
        //         output.push_back(pair.first);
        //     }
        // }
        // return output;
    }
};