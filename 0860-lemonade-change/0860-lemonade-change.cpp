class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0, ten = 0;

        for (auto& b : bills) {
            if (b > 5 && five == 0) {
                return false;
            }

            if (b == 5) {
                five++;
            }

            else if (b == 10) {
                ten++;
                five--;
            }


            else {
                if (ten) {
                    ten--;
                    five--;
                }
                else {
                    five -= 3;
                }
                
                if (five < 0) {
                    return false;
                }
            }
            cout<<five<< " "<<ten<< endl;
        }

        return true;
        
    }
};