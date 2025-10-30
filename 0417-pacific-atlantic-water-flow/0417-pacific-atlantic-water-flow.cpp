class Solution {
public:
int ROWS, COLS;
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));

        vector<vector<int>> result;

        queue<pair<int, int>> QP;
        queue<pair<int, int>> QA;

        for (int i = 0; i < ROWS; i++) {
            pacific[i][0] = true;
            QP.push({i, 0});
            atlantic[i][COLS - 1] = true;
            QA.push({i, COLS - 1});
        }

        for (int i = 0; i < COLS; i++) {
            pacific[0][i] = true;
            QP.push({0, i});
            atlantic[ROWS - 1][i] = true;
            QA.push({ROWS - 1, i});
        }

        pacific = dfs(heights, pacific, QP);
        atlantic = dfs(heights, atlantic, QA);

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (pacific[i][j] == true && atlantic[i][j] == true) {
                    result.push_back({i, j});
                }
            }
        }

        return result;



    }

    vector<vector<bool>> dfs(vector<vector<int>>& heights, vector<vector<bool>>& visit, queue<pair<int, int>>& queue) {

        while (!queue.empty()) {
            pair<int, int> cur = queue.front();
            queue.pop();
            

            for (int i = 0; i < 4; i++) {
                int r = cur.first + directions[i][0];
                int c = cur.second + directions[i][1]; 
                
                if (r >= 0 && r < ROWS && c >= 0 && c < COLS && 
                heights[r][c] >= heights[cur.first][cur.second] && 
                visit[r][c] != true) {
                    visit[r][c] = true;
                    queue.push({r, c});
                }
            }
        }

        return visit;
    }
};