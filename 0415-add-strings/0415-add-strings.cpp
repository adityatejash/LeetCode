class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        if (num1.size() < num2.size()) {
            int n = num2.size() - num1.size();

            while (n--) {
                num1 += "0";
            }
        } else {
            int n = num1.size() - num2.size();

            while (n--) {
                num2 += "0";
            }
        }


        int carry = 0;
        int m = num1.size();

        string ans;
        for (int i=0; i<m; i++) {
            int res = carry + (num1[i] - '0') + (num2[i] - '0');

            ans += to_string(res % 10);

            carry = res / 10;
        }

        if (carry) ans += to_string(carry);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};