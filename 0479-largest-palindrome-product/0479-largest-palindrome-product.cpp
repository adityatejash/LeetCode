class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;

        long long l = pow(10, n - 1);
        long long r = pow(10, n) - 1;

        for (long long i = r; i >= l; i--) {

            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());

            long long palindrome = stoll(s + rev);

            for (long long j = r; j * j >= palindrome; j--) {
                if (palindrome % j == 0) {
                    long long other = palindrome / j;

                    if (other >= l && other <= r)
                        return palindrome % 1337;
                }
            }
        }

        return -1;
    }
};