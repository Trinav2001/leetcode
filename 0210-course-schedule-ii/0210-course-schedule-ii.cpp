class Solution {
public:
int ROWS;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ROWS = prerequisites.size();
        vector<vector<int>> adjacent(numCourses);
        vector<int> in_arrows(numCourses, 0);

        queue<int> queue;

        for (auto& p : prerequisites) {
            int u = p[0];
            int v = p[1];
            adjacent[v].push_back(u);
            in_arrows[u]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (in_arrows[i] == 0) {
                queue.push(i);
            }
        }
        int courses_taken = 0;
        vector<int> result;
        
        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop();
            result.push_back(curr);
            courses_taken++;

            for (auto& adj : adjacent[curr]) {
                in_arrows[adj]--;
                if (in_arrows[adj] == 0) {
                    queue.push(adj);
                }
            }
        
        }
    
        // if (courses_taken == numCourses) {
        //     return result
        // }

        return (courses_taken == numCourses) ? result : vector<int>{};
    }
};