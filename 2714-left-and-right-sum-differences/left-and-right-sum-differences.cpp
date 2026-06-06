class Solution {
public:
    void helper (vector<int>& v1, vector<int>& v2){
        for (int i=0; i<v1.size(); i++){
            int x = i-1;
            if (x < 0){
                v2.push_back(0);
            } else {
                v2.push_back(v1[x] + v2.back());
            }
        }
    }

    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum;
        vector<int> rightSum;

        helper(nums, leftSum);

        reverse(nums.begin(), nums.end());

        helper(nums, rightSum);

        reverse(rightSum.begin(), rightSum.end());

        for (int i=0; i<nums.size(); i++){
            nums[i] = abs(leftSum[i] - rightSum[i]);
        }

        return nums;
    }
};