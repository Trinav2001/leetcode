class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // Method - 1

        if(nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        
        int currentStreak = 1;
        int finalStreak = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) continue;

            if(nums[i] - nums[i-1] == 1) {
                currentStreak += 1;
            }

            else {
                currentStreak = 1;
            }
            finalStreak = max(currentStreak, finalStreak);
        }
        return finalStreak;
    }
};