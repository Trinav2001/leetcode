class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];

        int n = intervals.size();

        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (intervals[i][0] > end) {

                res.push_back({start, end});
                for (int j = i; j < n; j++) {
                    res.push_back(intervals[j]);
                }
                    
                return res;
                
            }

            else if (start > intervals[i][1]) {
                res.push_back(intervals[i]);
            }

            else {
                start = min(intervals[i][0], start);
                end = max(intervals[i][1], end);

            }
        }

        res.push_back({start, end});
        return res;
    }
};