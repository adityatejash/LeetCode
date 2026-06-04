class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> l(26, -1);
        vector<int> u(26, -1);

        for (int i=0; i<word.size(); i++){
            if (islower(word[i])) l[word[i] - 'a'] = i;

            else {
                int ind = word[i] - 'A';
                if (u[ind] == -1) u[ind] = i;
            }
        }

        int ans = 0;
        for (int i=0; i<26; i++){
            if (l[i] != -1 &&
                u[i] != -1 &&
                l[i] < u[i]
            ) ans++;
        }

        return ans;
    }
};