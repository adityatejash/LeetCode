class Solution {
public:
    bool checkString(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == 'b') {
                st.push(c);
            } else {
                if (!st.empty()) {
                    return false;
                }
            }
        }

        return true;
    }
};