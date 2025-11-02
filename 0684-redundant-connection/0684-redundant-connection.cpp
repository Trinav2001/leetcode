class Solution {
public:
int SIZE;
vector<vector<int>> adjacent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        SIZE = edges.size() + 1;
        vector<int> result;
        adjacent.resize(SIZE);
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!Cycle(u, v)) {
                adjacent[u].push_back(v);
                adjacent[v].push_back(u);
            }
            else {
                result = edge;
                break;
            }
        }
        return result;
        
        
    }

    bool Cycle (int u, int v) {
        vector<bool> isVisited(SIZE, 0);

        queue<int> queue;
        queue.push(u);
        while (!queue.empty()) {
            int x = queue.front();
            queue.pop();

            if (x == v) {
                return true;
            }

            if (!isVisited[x]) {

                isVisited[x] = true;
                for (auto& edge : adjacent[x]) {
                    queue.push(edge);
                }
            } 
        }

        return false;
    }
};