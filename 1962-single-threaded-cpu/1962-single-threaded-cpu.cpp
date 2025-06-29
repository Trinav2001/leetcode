class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        int n = tasks.size();
        for(int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());

        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> minHeap;
        long long time = tasks[0][0];
        int i = 0;

        while(!minHeap.empty() || i < n) {
            while(i < n && time >= tasks[i][0]) {
                minHeap.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            if(minHeap.empty()) {
                time = tasks[i][0];
            }
            else {
                pair<int, int> p = minHeap.top();
                auto proctime = p.first;
                auto index = p.second;
                
                minHeap.pop();
                time += proctime;
                res.push_back(index);
            }
        }
        return res;

    }
};