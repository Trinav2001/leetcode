class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> output;
        
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int idx = it - arr.begin();
        int right = idx;
        int left = right - 1;

        int window = right - left - 1;
        
        while(window < k) {
            if (left < 0) right++;
            else if (right >= arr.size()) left--;
            else {
                if (abs(x - arr[left]) <= abs(x - arr[right])) left--;
                else right++;
            }
            window = right - left - 1;
        }

        for(int i = left + 1; i < right; i++) {
            output.push_back(arr[i]);
        }


        
        return output;
    }
};