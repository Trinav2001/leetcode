class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = *max_element(piles.begin(), piles.end());


        int start = 1;
        int end = maxElement;
        int answer = -1;

        while (start <= end) {
            long long totalTime = 0;
            int mid = start + (end - start) / 2;

            for (int i = 0; i < piles.size(); i++) {
                totalTime += ceil((double)piles[i] / mid);
            }

            if (totalTime <= h) {
                end = mid - 1;
                answer = mid;
                
            }
            else {
                start = mid + 1;
            }

        }

        return answer;
        
    }
};