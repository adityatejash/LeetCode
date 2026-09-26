class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map <string, string> m;

        for (auto& a : knowledge) {
            string key = a[0];
            string value = a[1];
            m[key] = value;
        }

        size_t open = s.find('(');

        while (open != string::npos) {
            size_t close = s.find(')', open);

            string key = s.substr(open+1, close-open-1);

            string value = "?";

            if (m.find(key) != m.end()) {
                value = m[key];
            }

            s.replace(open, close-open+1, value);

            open = s.find('(', open + value.size());
        }

        return s;
    }
};