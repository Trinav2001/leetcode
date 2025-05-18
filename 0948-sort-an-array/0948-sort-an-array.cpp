class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void MergeSort(vector<int>& nums, int l, int h) {
        if(l < h) {
            int mid = (l + h) / 2;
            MergeSort(nums, l, mid);
            MergeSort(nums, mid + 1, h);
            Merge(nums, l, mid, h);
        }
    }

    void Merge(vector<int>& nums, int l, int mid, int h) {
        vector<int> temp;
        int i = l;
        int j = mid + 1;
        int k;
        while(i <= mid && j <= h) {
            if(nums[i] < nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= h) {
            temp.push_back(nums[j]);
            j++;
        }
        for(k = 0; k < temp.size(); k++) {
            nums[l + k] = temp[k];
        }
    }

};