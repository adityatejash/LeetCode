class Solution {
public:
    bool isVowel (char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.size();

        vector<int> count(n, 0);

        if (isVowel(s[0])) count[0] = 1;

        for (int i=1; i<n; i++) {
            count[i] = count[i-1];

            if (isVowel(s[i])) count[i]++;
        }

        int ans = count[k-1];

        for (int j=k; j<n; j++) {
            int i = j - k;

            int vowels = count[j] - count[i];

            ans = max(ans, vowels);
        }

        return ans;
    }
};