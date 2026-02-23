class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> output;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int index = it - arr.begin();
        
        int left, right;
        left = index;
        right = index;

        if (index == arr.size()) {
            left--;
            right--;
        }

        else if (index > 0 && abs(x - arr[index - 1]) <= abs(x - arr[index])) {
            left--;
            right--;
        }
        
      

        int window = right - left + 1;

        while (window < k) {
            if (left <= 0) {
                right++;
            }
            else if (right >= arr.size() - 1) {
                left--;
            }

            else {
                if (abs(x - arr[left - 1]) <= abs(x - arr[right + 1])) {
                    left--;
                }

                else {
                    right++;
                }
            }

            window = right - left + 1;
        }

        for (int i = left; i <= right; i++) {
            output.push_back(arr[i]);

        }

        return output;
        
    }
};