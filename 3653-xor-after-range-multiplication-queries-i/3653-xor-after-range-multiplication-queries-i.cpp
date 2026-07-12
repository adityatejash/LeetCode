class Solution {
public:
    const static int mod = 1000000007;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto& a : queries){
            int l = a[0];
            int r = a[1];
            int k = a[2];
            int v = a[3];

            int idx = l;
            while (idx <= r){
                nums[idx] = (1LL * nums[idx] * v) % mod;
                idx += k;
            }
        }

        int ans = nums[0];
        for (int i=1; i<nums.size(); i++){
            ans ^= nums[i];
        }

        return ans;
    }
};