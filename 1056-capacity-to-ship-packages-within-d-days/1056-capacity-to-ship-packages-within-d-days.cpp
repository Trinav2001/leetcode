class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int res = end;

        while(start <= end) {
            int curr = (start + end) / 2;
            if(canShip(weights, days, curr)) {
                res = curr;
                end = curr - 1;
            }
            else {
                start = curr + 1;
            }
        }
        return res;
    }

    bool canShip(vector<int>& weights, int days, int curr) {
        int ships = 1;
        int k = curr;

        for(auto& w : weights) {
            if((k - w) < 0) {
                ships++;
                if(ships > days) return false;
                k = curr;
            }
            k -= w;
        }
        return true;
    }
};