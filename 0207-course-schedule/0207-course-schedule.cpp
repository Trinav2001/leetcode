class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        vector<vector<int>> adjacent(numCourses);

        vector<int> visited(numCourses, 0);

        for (auto& edges : prerequisites) {
            int u = edges[0];
            int v = edges[1];
            adjacent[v].push_back(u);

        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 && !dfs(i, adjacent, visited))  return false;
        }

        return true;
        
    }


    bool dfs (int i, vector<vector<int>>& adjacent, vector<int>& visited) {
        if (visited[i] == 1) {
            return false;
        }

        if (visited[i] == 2) {
            return true;
        }

        visited[i] = 1;

        for (auto& edge : adjacent[i]) {
            if (!dfs(edge, adjacent, visited)) return false;
        }

        visited[i] = 2;

        return true;
    }
};