class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> count(26, 0);
        for(auto& task : tasks) {
            count[task - 'A']++;
        }

        int maxfreq = *max_element(count.begin(), count.end());
        int maxCount = 0;
        for(int c : count) {
            if(c == maxfreq) {
                maxCount++;
            }
        }


        int time = (maxfreq - 1) * (n + 1) + maxCount;

        return max((int)tasks.size(), time);
    }
};