class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> queue;

        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    queue.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;
        if (queue.empty()) return -1;

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int time = -1;
        while (!queue.empty()) {
            int size = queue.size();
            time++;
            while (size--) {
                pair<int, int> p = queue.front();
                queue.pop();
                
                for (int i = 0; i < 4; i++) {
                    int r = p.first;
                    int c = p.second;
                    r = r + directions[i][0];
                    c = c + directions[i][1];

                    if (r < 0 || r >= rows || c < 0 || c >= cols 
                    || grid[r][c] == 0 || grid[r][c] == 2) { 
                        continue;
                    }
                    cout<<i << endl;

                    if (grid[r][c] == 1) {
                        cout<<"got in"<<endl;
                        grid[r][c] = 2;
                        fresh--;
                        queue.push({r, c});
                    }
                }
            }
        }
        cout<<fresh;
        return fresh == 0 ? time : -1;
        
    }
};