class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> m;

        int i = 0;
        int j = 0;
        int ans = 0;

        while (j < n) {
            m[nums[j]] ++;

            while (i < j && m[nums[j]] > k) {
                m[nums[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};