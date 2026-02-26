class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;

            if (count.size() <= 2) {
                continue;
            }

            unordered_map<int, int> newCount;

            for (auto& pair : count) {

                if (pair.second > 1) {
                    newCount[pair.first] = pair.second - 1;
                }                
            }

            count = newCount;

        }

        vector<int> res;
        int n = nums.size();

        for (auto& pair : count) {
            int freq = 0;

            for (auto& num : nums) {
                if (pair.first == num) {
                    freq++;
                }
            }
            if (freq > n / 3) {
                res.push_back(pair.first);
            }

        }

        return res;
        
    }
};