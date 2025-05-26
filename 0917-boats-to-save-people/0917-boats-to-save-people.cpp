class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int i = 0;
        int j = people.size() - 1;
        int weight = 0;
        int res = 0;
        while(i <= j) {
            weight = people[i] + people[j];
            if(weight <= limit) {
                i++;
                j--;
            }
            else {
                j--;
            }
            res++;
        }

        return res;
    }
};