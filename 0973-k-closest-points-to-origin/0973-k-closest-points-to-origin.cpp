class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto comp = [](vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap;

        vector<vector<int>> res;

        for (auto& pt : points) {
            minHeap.push(pt);
        }

        while (k--) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }

        return res;


        
    }
};