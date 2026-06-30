class Solution {
public:
    bool isPresent(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }

    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1;

        for (int i = 0; i < nums.size(); i++) {
            int temp = 1;
            long long sq = 1LL * nums[i] * nums[i];

            while (sq <= INT_MAX && isPresent(nums, (int)sq)) {
                temp++;
                sq = sq * sq;
            }

            ans = max(ans, temp);
        }

        return (ans >= 2) ? ans : -1;
    }
};