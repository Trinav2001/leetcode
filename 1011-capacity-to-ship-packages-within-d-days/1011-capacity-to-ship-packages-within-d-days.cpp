class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int h = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());

        int res = h;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (canShip(weights, days, mid)) {
                res = mid;
                h = mid - 1;
            }

            else {
                l = mid + 1;
            }
        }

        return res;
   
    }

    bool canShip(vector<int>& weights, int days, int mid) {

        int ship = 1;
        int capacity = mid;

        for (auto& w : weights) {
            if (mid < w) {
                ship++;
                if (ship > days) {
                    return false;
                }
                mid = capacity;
            }
            mid = mid - w;
        }

        return true;

    }
};