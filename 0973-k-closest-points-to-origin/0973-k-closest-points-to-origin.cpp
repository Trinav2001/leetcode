class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // For priority_queue, comparator defines when one element should be 
        // considered lower priority than another. 
        
        // a has lower priority than b if dist(a) > dist(b)
        auto comp = [](vector<int> a, vector<int> b) {
            long long distA = a[0] * a[0] + a[1] * a[1];
            long long distB = b[0] * b[0] + b[1] * b[1];

            return distA > distB;
        };

        
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap;
        vector<vector<int>> res;

        for (auto& pts : points) {
            minHeap.push(pts);
        }


        while (k--) {
            res.push_back(minHeap.top());
            minHeap.pop();

        }

        return res;


        
    }
};