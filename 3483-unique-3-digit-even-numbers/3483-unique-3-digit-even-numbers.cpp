class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> ans;

        for (int i=0; i<n-2; i++) {
            for (int j=i+1; j<n-1; j++) {
                for (int k=j+1; k<n; k++) {
                    int t1 = digits[i] * 100 + digits[j] * 10 + digits[k];
                    int t2 = digits[i] * 100 + digits[k] * 10 + digits[j];
                    int t3 = digits[j] * 100 + digits[i] * 10 + digits[k];
                    int t4 = digits[j] * 100 + digits[k] * 10 + digits[i];
                    int t5 = digits[k] * 100 + digits[i] * 10 + digits[j];
                    int t6 = digits[k] * 100 + digits[j] * 10 + digits[i];

                    if (t1 % 2 == 0 && t1 > 99) {
                        ans.insert(t1);
                    }
                    if (t2 % 2 == 0 && t2 > 99) {
                        ans.insert(t2);
                    }
                    if (t3 % 2 == 0 && t3 > 99) {
                        ans.insert(t3);
                    }
                    if (t4 % 2 == 0 && t4 > 99) {
                        ans.insert(t4);
                    }
                    if (t5 % 2 == 0 && t5 > 99) {
                        ans.insert(t5);
                    }
                    if (t6 % 2 == 0 && t6 > 99) {
                        ans.insert(t6);
                    }
                }
            }
        }

        return ans.size();
    }
};