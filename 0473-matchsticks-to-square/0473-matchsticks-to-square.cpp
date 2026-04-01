class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) {
            return false;
        }

        int targetSide = sum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<int> sides(4, 0);

        return backtrack(matchsticks, sides, 0, targetSide);
        
    }

    bool backtrack(vector<int>& matchsticks, vector<int>& side, int i, int targetSide) {
        if (i == matchsticks.size()) {
            return true;
        }

        for (int k = 0; k < 4; k++) {
            if (side[k] + matchsticks[i] <= targetSide) {
                side[k] += matchsticks[i];
                if (backtrack(matchsticks, side, i + 1, targetSide)) {
                    return true;
                }
                side[k] -= matchsticks[i];

            }
        }

        return false;
    }
};