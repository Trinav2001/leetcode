class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> output;

        int i = 0;
        int j = numbers.size() - 1;
        while(i < j) {
            if((numbers[i] + numbers[j]) > target) {
                j--;
            }
            else if((numbers[i] + numbers[j]) < target) {
                i++;
            }
            else{
                output.push_back(i + 1);
                output.push_back(j + 1);
                i++;
                j--;
            }
        }
        return output;
    }
};