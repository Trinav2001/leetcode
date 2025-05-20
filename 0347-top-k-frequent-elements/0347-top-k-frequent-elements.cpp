class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Method - 2
        unordered_map<int, int> map;
        for(auto& val : nums) {
            map[val]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for(auto& entry : map) {
            heap.push({entry.second, entry.first}); 
            if(heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> output;
        while(!heap.empty()) {
            output.push_back(heap.top().second);
            heap.pop();
        }
        return output;



        // Method - 1
        // unordered_map<int, int> map;
        // for(auto& key : nums) {
        //     map[key]++;
        // }

        // vector<pair<int, int>> array;
        // for(auto& [k, v] : map) {
        //     array.push_back({v ,k});
        // }

        // sort(array.rbegin(), array.rend());
        // vector<int> output;
        // for(int i = 0; i < k; i++) {
        //     output.push_back(array[i].second);
        // }
        // return output;
    }
};