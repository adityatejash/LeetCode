class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> characters(26, 0);

        for (char c : s) {
            characters[c - 'a']++;
        }

        set<int> st;

        for (int freq : characters) {
            if (freq > 0) st.insert(freq);
        }

        return st.size() == 1;
    }
};