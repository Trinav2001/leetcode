class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = 1;
        int curMin = 1;
        int res = INT_MIN;
        for (auto& num : nums) {
            int temp = num * curMax;
            curMax = max(max(num * curMax, num * curMin), num);
            curMin = min(min(num * curMin, temp), num);
            // cout<<curMax<<"    "<<curMin<<endl;
            res = max(res, curMax);
        }

        return res;
        
    }
};