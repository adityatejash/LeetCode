class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int M = INT_MIN;
        int m = INT_MAX;

        for (int n : nums) {
            if (n > M) M = n;
            if (n < m) m = n;
        }

        int range = M - m + 1;
        vector<int> freq (range, 0);

        for (int n : nums) {
            freq[n-m]++;
        }

        vector<int> ans;
        for (int i=0; i<range; i++) {
            while (freq[i] > 0) {
                ans.push_back(i+m);
                freq[i]--;
            }
        }

        return ans;
    }
};