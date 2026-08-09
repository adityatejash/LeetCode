class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();

        int i=0;
        int j=n-1;

        int ans = 0;
        while (i <= j) {
            if (nums[i] == 0 && nums[j] != 0) {
                swap(nums[i], nums[j--]);
                ans++;
            }

            if (nums[i] != 0) {
                i++;
            } else if (nums[j] == 0) {
                j--;
            }            
        }

        return ans;
    }
};