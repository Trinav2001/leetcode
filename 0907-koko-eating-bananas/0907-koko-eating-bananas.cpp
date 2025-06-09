class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = *max_element(piles.begin(), piles.end());
        int start = 1;
        int end = maxElement;
        int res = end;

        while(start <= end) {
            int m = start + (end - start) / 2;
            long long totalTime = 0;
            for(auto val : piles) {
                totalTime += ceil(double(val) / m);
            }

            if(totalTime <= h) {
                res = m;
                end = m - 1;
            }
            else {
                start = m + 1;
            }
        }
        return res;
    }
};