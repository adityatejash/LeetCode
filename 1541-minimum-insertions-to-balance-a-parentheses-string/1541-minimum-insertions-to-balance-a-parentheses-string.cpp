class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push('(');
                st.push('(');
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }

                if (st.empty()) {
                    ans++;
                } else {
                    st.pop();
                    st.pop();
                }
            }
        }

        ans += st.size();
        return ans;
    }
};