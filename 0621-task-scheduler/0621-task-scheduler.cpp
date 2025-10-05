class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;

        vector<int> count(26, 0);
        for (auto& task : tasks) {
            count[task - 'A']++;
        }

        for (auto& cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        queue<pair<int, int>> queue;
        int time = 0;
        while (!maxHeap.empty() || !queue.empty()) {
            
            time++;
            if (!maxHeap.empty()) {
                int count = maxHeap.top() - 1;
                maxHeap.pop();

                if (count > 0) {
                    queue.push({count, time + n});
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