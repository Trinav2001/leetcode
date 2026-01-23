class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        

        vector<int> count(26, 0);

        priority_queue<int, vector<int>> maxHeap;
        
        for (auto& t : tasks) {
            count[t - 'A']++;
        }

        for (auto& cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        int time = 0;
        queue<pair<int, int>> queue;

        while (!queue.empty() || !maxHeap.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int top = maxHeap.top() - 1;
                maxHeap.pop();

                if (top > 0) {
                    queue.push({top, time + n});
                }
            }

            if (!queue.empty() && queue.front().second == time) {
                maxHeap.push(queue.front().first);
                queue.pop();
            }
        }
        return time;

        

        
        
    }
};