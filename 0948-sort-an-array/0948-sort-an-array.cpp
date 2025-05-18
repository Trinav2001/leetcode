class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // MergeSort(nums, 0, nums.size() - 1);
        // return nums;
        // nums.push_back(INT32_MAX);
        // QuickSort(nums, 0, nums.size()-1);
        // nums.pop_back();
        // return nums;
        // SelectionSort(nums);
        // return nums;
        // CountSort(nums);
        // return nums;
        
        vector<int> negatives, positives;
        for(auto& num : nums) {
            if(num < 0) {
                negatives.push_back(-num);
            }
            else {
                positives.push_back(num);
            }
        }

        if(!negatives.empty()) {
            RadixSort(negatives);
            reverse(negatives.begin(), negatives.end());
            for(auto& num : negatives) {
                num = -num;
            }
        }

        if(!positives.empty()) {
            RadixSort(positives);
        }

        nums.clear();
        for(auto& num : negatives) {
            nums.push_back(num);
        }

        for(auto& num : positives) {
            nums.push_back(num);
        }

        return nums;


    }

    void RadixSort(vector<int>& nums) {
        int n = nums.size();
        int max = *max_element(nums.begin(), nums.end());
        int exp = 1;
        while(max / exp > 0) {
            CountSort(nums, n, exp);
            exp = exp * 10;
        }
    }

    void CountSort(vector<int>& nums, int n, int exp) {
        vector<int> count(10, 0);
        for(int i = 0; i < n; i++) {
            int digit = (nums[i] / exp) % 10;
            count[digit]++;
        }

        for(int i = 1; i < count.size(); i++) {
            count[i] = count[i] + count[i-1];
        }

        vector<int> output(n);

        for(int i = n - 1; i >= 0; i--) {
            int digit = (nums[i] / exp) % 10;
            output[--count[digit]] = nums[i];
        }

        for(int i = 0; i < n; i++) {
            nums[i] = output[i];
        }
    }


    // void CountSort(vector<int>& nums) {
    //     unordered_map<int, int> map;
    //     int min = *min_element(nums.begin(), nums.end());
    //     int max = *max_element(nums.begin(), nums.end());

    //     for(auto& val : nums) {
    //         map[val]++;
    //     }

    //     int index = 0;
    //     for(int val = min; val <= max; ) {
    //         if(map[val] > 0) {
    //             nums[index++] = val;
    //             map[val]--;
    //         }
    //         else {
    //             val++;
    //         }
    //     }
    // }

    // void SelectionSort(vector<int>& nums) {
    //     int i;
    //     int j, k;
    //     for(i = 0; i < nums.size() - 1; i++) {
    //         for(j = i, k = i; j < nums.size(); j++) {
    //             if(nums[j] < nums[k]) {
    //                 k = j;
    //             }
    //         }
    //         swap(nums[i], nums[k]);
    //     }
    // }

    // void QuickSort(vector<int>& nums, int l, int h) {
    //     int j;
    //     if(l < h) {
    //         j = Partition(nums, l, h);
    //         QuickSort(nums, l, j);
    //         QuickSort(nums, j+1, h);
    //     }
    // }

    // int Partition(vector<int>& nums, int l, int h) {
    //     int pivot = nums[l];
    //     int i = l;
    //     int j = h;
    //     do{
    //         do{i++;} while(i <= h && nums[i] <= pivot);
    //         do{j--;} while(j >= l && nums[j] > pivot);
    //         if(i < j) 
    //             swap(nums[i], nums[j]);

    //     } while(i < j);
    //     swap(nums[l], nums[j]);
    //     return j;
    // }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    // void MergeSort(vector<int>& nums, int l, int h) {
    //     if(l < h) {
    //         int mid = (l + h) / 2;
    //         MergeSort(nums, l, mid);
    //         MergeSort(nums, mid + 1, h);
    //         Merge(nums, l, mid, h);
    //     }
    // }

    // void Merge(vector<int>& nums, int l, int mid, int h) {
    //     vector<int> temp;
    //     int i = l;
    //     int j = mid + 1;
    //     int k;
    //     while(i <= mid && j <= h) {
    //         if(nums[i] < nums[j]) {
    //             temp.push_back(nums[i]);
    //             i++;
    //         }
    //         else {
    //             temp.push_back(nums[j]);
    //             j++;
    //         }
    //     }
    //     while(i <= mid) {
    //         temp.push_back(nums[i]);
    //         i++;
    //     }
    //     while(j <= h) {
    //         temp.push_back(nums[j]);
    //         j++;
    //     }
    //     for(k = 0; k < temp.size(); k++) {
    //         nums[l + k] = temp[k];
    //     }
    // }

};