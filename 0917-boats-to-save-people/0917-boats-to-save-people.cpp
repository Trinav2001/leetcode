class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        int m = *max_element(people.begin(), people.end());
        vector<int> count(m + 1, 0);

        for(auto& val : people) {
            count[val]++;
        }

        int index = 0;
        int i = 0;
        while(index < people.size()) {
            while(count[i] != 0) {
                count[i]--;
                people[index++] = i;
            }
            i++;            
        }

        int l = 0;
        int r = people.size() - 1;
        int rem = 0;
        int result = 0;

        while(l <= r) {
            rem = limit - people[r--];
            result++;

            if(l <= r && rem >= people[l]) {
                l++;
            }
        }

        return result;


        // Method - 1
        // sort(people.begin(), people.end());

        // int i = 0;
        // int j = people.size() - 1;
        // int weight = 0;
        // int res = 0;
        // while(i <= j) {
        //     weight = people[i] + people[j];
        //     if(weight <= limit) {
        //         i++;
        //         j--;
        //     }
        //     else {
        //         j--;
        //     }
        //     res++;
        // }

        // return res;
    }
};