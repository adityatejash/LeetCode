class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0, y = 0;

        unordered_map<char, int> m;

        for (char c : secret) {
            m[c]++;
        }

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                x++;
                m[secret[i]]--;
                if (m[secret[i]] == 0) {
                    m.erase(secret[i]);
                }
            }
        }

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] != guess[i] && m.find(guess[i]) != m.end()) {
                y++;
                m[guess[i]]--;
                if (m[guess[i]] == 0) {
                    m.erase(guess[i]);
                }
            }
        }

        return to_string(x) + "A" + to_string(y) + "B";
    }
};