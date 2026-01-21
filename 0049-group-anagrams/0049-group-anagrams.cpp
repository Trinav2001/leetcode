class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (auto& str : strs) {
            vector<int> count(26, 0);
            for (auto c : str) {
                count[c - 'a']++;
            }

            string key = "";

            for (auto i : count) {
                key = key + to_string(i) + ",";
            }

            map[key].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto& pair : map) {
            ans.push_back(pair.second);

        }

        return ans;
        
    }
};