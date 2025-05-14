class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Method - 2
        unordered_map<string, vector<string>> map;
        for(auto s : strs) {
            vector<int> count(26, 0);
            for(auto c : s) {
                count[c - 'a']++;
            }
            string key = "";
            for(auto i : count) {
                key = key + to_string(i) + ",";
            }
            map[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& pair : map) {
            ans.push_back(pair.second);
        }
        return ans;

        
        // Method - 1
        // unordered_map<string, vector<string>> map;
        // for(auto s : strs) {
        //     string key = s;
        //     sort(key.begin(), key.end());
        //     map[key].push_back(s);
        // }
        // vector<vector<string>> ans;
        // for(auto& pair : map) {
        //     ans.push_back(pair.second);
        // }
        // return ans;
    }
};