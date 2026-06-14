class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for (char c : s){
            if (c >= 'a' && c <= 'z') st.push(c);

            else st.pop();
        }

        string newS = "";
        while (! st.empty()){
            newS += st.top();
            st.pop();
        }

        reverse(newS.begin(), newS.end());

        return newS;
    }
};