class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& arr, int l, int h) {
        if (l >= h) {
            return;
        }
        int m = l + (h - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        merge(arr, l, m, h);


    }



    void merge(vector<int>& arr, int l, int m, int h) {

        vector<int> temp;
        int i = l;
        int j = m + 1;

        while (i <= m && j <= h) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }

            else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while (i <= m) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= h) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int it = 0; it < temp.size(); it++) {
            arr[l++] = temp[it];
        }

    }
};