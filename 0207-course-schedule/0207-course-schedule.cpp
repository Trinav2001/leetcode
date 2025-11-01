class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adjacent(n);
        vector<int> visited(n, 0);

        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adjacent[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && !dfs (i, adjacent, visited)) return false;
        }
        return true;

        
    }

    bool dfs (int u, vector<vector<int>>& adjacent, vector<int>& visited) {

        if (visited[u] == 1) return false;;

        if (visited[u] == 2) return true;


        visited[u] = 1;

        for (auto& edge : adjacent[u]) {
            if (!dfs (edge, adjacent, visited)) {
                return 0;
            }
        }
        visited[u] = 2;

        return 1;
    }
};