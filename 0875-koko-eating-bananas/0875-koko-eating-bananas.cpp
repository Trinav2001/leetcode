class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxElement = *max_element(piles.begin(), piles.end());

        int start = 1;
        int end = maxElement;

        int res = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            long long totalTime = 0;
            for (auto& p : piles) {
                totalTime += ceil((double)p / mid);
            }

            if (totalTime <= h) {
                res = mid;
                end = mid - 1;
            }

            else {
                start = mid + 1;
            }


        }

        return res;



        
    }
};