class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Method - 2
        unordered_set<int> set;
        for(auto& num : nums) {
            set.insert(num);
        }

        int maxLength = 0;

        for(auto& num : set) {
            if(set.find(num - 1) != set.end()) {
                continue;
            }

            int currentLength = 1;
            int currentNum = num;
            while(set.find(currentNum + 1) != set.end()) {
                currentLength += 1;
                currentNum += 1;
            }

            maxLength = max(maxLength, currentLength);
        }
        return maxLength;




        // Method - 1

        // if(nums.size() == 0) {
        //     return 0;
        // }
        // sort(nums.begin(), nums.end());
        
        // int currentStreak = 1;
        // int finalStreak = 1;
        // for(int i = 1; i < nums.size(); i++) {
        //     if(nums[i] == nums[i-1]) continue;

        //     if(nums[i] - nums[i-1] == 1) {
        //         currentStreak += 1;
        //     }

        //     else {
        //         currentStreak = 1;
        //     }
        //     finalStreak = max(currentStreak, finalStreak);
        // }
        // return finalStreak;
    }
};