class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = -1;
        priority_queue<int> maxHeap;
        queue<pair<int, int>> queue;    // (count_of_task, next_ready_to_schedule_time)
        vector<int> count(26, 0);

        for (auto& task : tasks) {
            count[task - 'A']++;
        }

        for (auto& c : count) {
            if (c > 0) {
                maxHeap.push(c);
            }
        }

        while (!maxHeap.empty() || !queue.empty()) {
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

        return time + 1;

        

        

        
        
    }
};