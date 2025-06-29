class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pair<int, char>> maxHeap;

        if(a > 0) maxHeap.push({a, 'a'});
        if(b > 0) maxHeap.push({b, 'b'});
        if(c > 0) maxHeap.push({c, 'c'});

        while(!maxHeap.empty()) {
            pair<int, char> p = maxHeap.top();
            int count = p.first;
            char ch = p.second;
            maxHeap.pop();

            if(res.size() > 1 && res[res.size() - 1] == ch && res[res.size() - 2] == ch) {
                if(maxHeap.empty()) break;
                pair<int, char> p2 = maxHeap.top();
                int count2 = p2.first;
                char ch2 = p2.second;
                maxHeap.pop();
                count2--;
                res += ch2;
                if (count2 > 0) maxHeap.push({count2, ch2});
                if(count > 0) maxHeap.push({count, ch});           
            }

            else {
                res += ch;
                count--;
                if(count > 0) maxHeap.push({count, ch});
            }

        }
        return res;

    }
};