class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(5, 0);

        for (char c : text){
            if (c == 'a'){
                v[0]++;
            } else if (c == 'b'){
                v[1]++;
            } else if (c == 'l'){
                v[2]++;
            } else if (c == 'n'){
                v[3]++;
            } else if (c == 'o'){
                v[4]++;
            }
        }

        return min ({
            v[0],
            v[1],
            v[2] / 2,
            v[3],
            v[4] / 2
        });
    }
};