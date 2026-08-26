class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0;
        int count = 0;
        
        int best = INT_MAX;
        string ans = "";
        
        for (int j=0; j<s.size(); j++) {
            if (s[j] == '1') count++;

            while (count == k) {
                int len = j - i + 1;

                string current = s.substr(i, len);

                if (len < best || (len == best && current < ans)) {
                    best = len;
                    ans = current;
                }

                if (s[i] == '1') count--;

                i++;
            }
        }

        return ans;
    }
};