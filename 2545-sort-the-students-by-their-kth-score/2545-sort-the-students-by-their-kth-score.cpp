class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int rows = score.size();
        int cols = score[0].size();

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < rows; i++) {
            pq.push({score[i][k], i});
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            res.push_back(score[pq.top().second]);
            pq.pop();
        }

        return res;
    }
};