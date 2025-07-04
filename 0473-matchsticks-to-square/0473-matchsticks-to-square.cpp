class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0) return false;

        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sides(4, 0);
        return backtrack(matchsticks, 0, sides, sum/4);
        
    }

    bool backtrack(vector<int>& matchsticks, int i, vector<int>& sides, int targetLength) {
        if(i == matchsticks.size()) {
            return true;
        }

        for(int j = 0; j < 4; j++) {
            if(sides[j] + matchsticks[i] <= targetLength) {
                sides[j] += matchsticks[i];
                if (backtrack(matchsticks, i + 1, sides, targetLength)) return true;
                sides[j] -= matchsticks[i];
            }
        }
        return false;
    }

};