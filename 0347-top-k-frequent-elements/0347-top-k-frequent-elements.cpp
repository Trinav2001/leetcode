class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(auto& key : nums) {
            map[key]++;
        }

        vector<pair<int, int>> array;
        for(auto& [k, v] : map) {
            array.push_back({v ,k});
        }

        sort(array.rbegin(), array.rend());
        vector<int> output;
        for(int i = 0; i < k; i++) {
            output.push_back(array[i].second);
        }
        return output;
    }
};