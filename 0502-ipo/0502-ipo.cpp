class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int, vector<int>> maxProfit; // MaxHeap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minCap; // MinHeap

        for(int i = 0; i < capital.size(); i++) {
            minCap.emplace(capital[i], profits[i]);
        }

        while(k-- != 0) {
            
            while(!minCap.empty() && minCap.top().first <= w) {
                maxProfit.push(minCap.top().second);
                minCap.pop();
            }

            if(maxProfit.empty()) break;

            w += maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};