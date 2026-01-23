class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int ROWS = grid.size();
        int COLS = grid[0].size();

        int fresh = 0;

        queue<pair<int, int>> queue;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
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
                    r += directions[i][0];
                    c += directions[i][1];

                    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == 2) {
                        continue;
                    }

                    if (grid[r][c] == 1) {
                        grid[r][c] = 2;
                        fresh--;
                        queue.push({r, c});
                    }
                }
            }
        }

        return fresh == 0 ? time : -1;
        
    }
};