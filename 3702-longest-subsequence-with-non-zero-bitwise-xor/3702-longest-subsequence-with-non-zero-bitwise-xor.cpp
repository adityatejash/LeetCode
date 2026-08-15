class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int temp = 0;

        for (int n : nums) {
            temp ^= n;
        }

        if (temp != 0) return nums.size();

        for (int n : nums) {
            if (n != 0) {
                return nums.size() -1;
            }
        }

        return 0;
    }
};