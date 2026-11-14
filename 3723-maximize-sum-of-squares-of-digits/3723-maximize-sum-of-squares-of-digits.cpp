class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        if (9*num < sum) return ans;

        for (int i = 0; i < num; i++) {
            int digit = min(9, sum);

            ans.push_back('0' + digit);

            sum -= digit;
        }

        return ans;
    }
};