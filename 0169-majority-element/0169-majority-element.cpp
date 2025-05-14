class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algo
        // Keep a count and a candidate
        // If the current number equals the candidate → count++
        // If different → count--
        // When count drops to 0 → choose the new candidate
        int count = 0;
        int candidate;
        for(auto val : nums) {
            if(count == 0) {
                candidate = val;
                count++;
            }
            else {
                if(candidate == val) {
                    count++;
                }
                else {
                    count--;
                }
            }
        }
        return candidate;


        // Method - 1
        // unordered_map<int, int> map;
        // for(auto key : nums) {
        //     map[key] += 1;
        // }
        // int ans = nums[0];
        // int freq = -1;
        // for(auto val : map) {
        //     if(val.second > freq) {
        //         freq = val.second;
        //         ans = val.first;
        //     }
        // }
        // return ans;
    }
};