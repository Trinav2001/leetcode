class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // end & passengers

        int curPass = 0;

        for(auto& trip : trips) {
            int pass = trip[0];
            int start = trip[1];
            int end = trip[2];

            while(!minHeap.empty() && minHeap.top().first <= start) {
                curPass -= minHeap.top().second;
                minHeap.pop();
            }
        
            curPass += pass;
            if (curPass > capacity) return false;

            minHeap.emplace(end, pass);
            

        }


        return true;
    }
};