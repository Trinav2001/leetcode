class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for(char& c : s) {
            freq[c - 'a']++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) maxHeap.push({freq[i], 'a' + i});
        }

        string res = "";
        pair<int, char> prev = {0, ' '};

        while(!maxHeap.empty() || prev.first > 0) {
            if(maxHeap.empty() && prev.first > 0) return "";

            pair<int, char> top = maxHeap.top();
            int count = top.first;
            char c = top.second;
            maxHeap.pop();
            res += c;
            count--;

            if(prev.first > 0) {
                maxHeap.push(prev);
                prev = {0, ' '};
            }

            if(count != 0)
                prev = {count, c};
        }
        return res;
    }
};