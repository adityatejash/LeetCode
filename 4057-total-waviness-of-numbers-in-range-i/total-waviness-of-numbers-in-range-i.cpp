class Solution {
public:
    int solve (int n){
        string s = to_string(n);

        if (s.size() < 3) return 0;

        int count = 0;

        for (int i=1; i<s.size()-1; i++){
            bool peak = (s[i] > s[i-1] && s[i] > s[i+1]);
            bool valley = (s[i] < s[i-1] && s[i] < s[i+1]);

            if (peak || valley) count++;
        }

        return count;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int i=num1; i<=num2; i++){
            ans += solve(i);
        }

        return ans;
    }
};