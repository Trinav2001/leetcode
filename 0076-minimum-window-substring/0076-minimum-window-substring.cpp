class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char, int> count;
        unordered_map<char, int> window;

        for(auto c : t) {
            count[c]++;
        }

        pair<int, int> indices = {-1, -1};
        int res = INT_MAX;
        int left = 0;
        int right;
        int have = 0;
        int need = count.size();

        for(right = 0; right < s.length(); right++) {
            char c = s[right];
            window[c]++;

            if(count.count(c) && window[c] == count[c]) {
                have++;
            }

            while(have == need) {
                if((right - left + 1) < res) {
                    res = right - left + 1;
                    indices = {left, right};
                }

                window[s[left]]--;

                if(count.count(s[left]) && window[s[left]] < count[s[left]]) {
                    have--;
                }
                left++;

            }
        }

        return res == INT_MAX ? "" : s.substr(indices.first, res);
    }
};