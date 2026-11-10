class Solution {
public:
    void countingSort(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end());
        int m = *min_element(nums.begin(), nums.end());

        int range = M - m + 1;

        vector<int> freq (range, 0);

        for (int n : nums) {
            freq[n - m]++;
        }

        int ind = 0;
        for (int i=0; i<range; i++) {
            while (freq[i] > 0) {
                nums[ind++] = i + m;
                freq[i]--;
            }
        }
    }
    int arrayPairSum(vector<int>& nums) {
        countingSort(nums);

        int sum = 0;
        for (int i=0; i<nums.size(); i+=2) {
            sum += nums[i];
        }

        return sum;
    }
};