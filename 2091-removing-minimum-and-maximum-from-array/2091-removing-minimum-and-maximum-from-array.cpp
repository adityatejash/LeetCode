class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;

        int minIndex;
        int maxIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minimum) {
                minimum = nums[i];
                minIndex = i;
            }

            if (nums[i] > maximum) {
                maximum = nums[i];
                maxIndex = i;
            }
        }

        int n = nums.size();

        // deleting from front
        int front = max(maxIndex, minIndex) + 1;

        // deleting from back
        int back = n - min(minIndex, maxIndex);

        // deleting from either front or back
        int mixed;
        if (minIndex < maxIndex) {
            mixed = (minIndex + 1) + (n - maxIndex);
        } else {
            mixed = (maxIndex + 1) + (n - minIndex);
        }

        return min({front, back, mixed});
    }
};