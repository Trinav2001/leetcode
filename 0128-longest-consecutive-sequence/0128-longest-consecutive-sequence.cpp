class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> set;
        for(auto& num : nums) {
            set.insert(num);
        }

        int maxLength = 0;
        for (auto& num : set) {
            if (set.find(num - 1) != set.end()) {
                continue;
            }

            int curStreak = 1;
            int curNum = num;

            while (set.find(curNum + 1) != set.end()) {
                curStreak++;
                curNum++;
            }

            maxLength = max(maxLength, curStreak);
        }

        return maxLength;
        
    }
};