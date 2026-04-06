class Solution {
public:
    string reorganizeString(string s) {
        string res = "";

        vector<int> freq(26, 0);

        for (auto& c : s) {
            freq[c - 'a']++;
        }

        priority_queue<pair<int, char>> maxHeap;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], i + 'a'});
            }
        }

        pair<int, char> prev = {0, ' '};

        while(!maxHeap.empty() || prev.first > 0) {
            if (maxHeap.empty()) {
                return "";
            }

            auto pair = maxHeap.top();
            int count = pair.first;
            char c = pair.second;
            res += c;
            
            maxHeap.pop();

            if (prev.first > 0) {
                maxHeap.push(prev);
                prev = {0, ' '};
            }

            if (--count) {
                prev = {count, c};
            }

            
        }

        return res;

        
    }
};