class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size() - 1;
        int res = 0;

        while (left <= right) {
            int weight = people[right--];
            int diff = limit - weight;

            if (left <= right && diff >= people[left]) {
                left++;
            }

            res++;
            
        }

        return res;
        
    }
};