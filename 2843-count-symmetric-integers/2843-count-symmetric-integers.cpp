class Solution {
public:
    bool isSymmetric (int num){
        string s = to_string(num);

        if (s.size() % 2 != 0) return false;

        int left = 0;
        int right = 0;

        int n = s.size();

        for (int i=0; i<n/2; i++){
            left += s[i] - '0';
        }

        for (int i=n/2; i<n; i++){
            right += s[i] - '0';
        }

        return left == right;
    }

    int solve (int low, int high){
        int count = 0;

        for (int i=low; i<=high; i++){
            if (isSymmetric(i)) count++;
        }

        return count;
    }

    int countSymmetricIntegers(int low, int high) {
        return solve(low, high);
    }
};