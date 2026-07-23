class Solution {
public:
    string decodeMessage(string key, string message) {
        char t = 'a';

        unordered_set<char> s;
        unordered_map<char, char> m;

        for (char c : key) {
            if (c == ' ') continue;

            if (s.find(c) == s.end()) {
                s.insert(c);
                m[c] = t++;
            }
        }

        string ans = "";

        for (char c : message) {
            if (c == ' ') ans += c;
            else ans += m[c];
        }

        return ans;
    }
};