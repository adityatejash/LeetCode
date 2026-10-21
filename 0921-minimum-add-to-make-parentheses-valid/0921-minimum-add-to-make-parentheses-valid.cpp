class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;

        stack<int> st;

        for (char c : s) {
            if (c == '(') {
                st.push('(');
            } else if (c == ')'){
                if (st.empty()) ans ++;

                else st.pop();
            }
        }

        return ans + st.size();
    }
};