class Solution {
public:
    string originalDigits(string s) {
        vector<int> freq (26, 0);
        for (char c: s) {
            freq[c - 'a']++;
        }

        vector<int> count (10, 0);

        vector<tuple<int, char, string>> order = {
            {0, 'z', "zero"},
            {2, 'w', "two"},
            {4, 'u', "four"},
            {6, 'x', "six"},
            {8, 'g', "eight"},
            {1, 'o', "one"},
            {3, 'h', "three"},
            {5, 'f', "five"},
            {7, 's', "seven"},
            {9, 'i', "nine"},
        };

        for (auto& [d, key, word] : order) {
            count[d] = freq[key - 'a'];
            for (char c : word) {
                freq[c - 'a'] -= count[d];
            }
        }

        string ans = "";
        for (int i=0; i<10; i++) {
            ans += string(count[i], '0' + i);
        }

        return ans;
    }
};