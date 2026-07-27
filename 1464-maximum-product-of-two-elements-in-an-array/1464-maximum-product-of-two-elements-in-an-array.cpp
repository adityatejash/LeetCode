class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fm = nums[0];
        int sm = nums[1];

        if (fm < sm) swap(fm, sm);

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] >= fm) {
                sm = fm;
                fm = nums[i];
            } else if (nums[i] > sm) {
                sm = nums[i];
            }
        }

        return (fm - 1) * (sm - 1);
    }
};