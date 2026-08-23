class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                leftQ++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                rightQ++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        int sumDiff = leftSum - rightSum;
        int qDiff = leftQ - rightQ;

        // Same number of '?' on both sides
        if (qDiff == 0) {
            return sumDiff != 0;
        }

        // Odd total number of '?'
        if ((leftQ + rightQ) % 2 != 0) {
            return true;
        }

        int maxDiff = 9 * qDiff / 2;

        return sumDiff != -maxDiff;
    }
};