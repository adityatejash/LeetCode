class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count_ = 0;
        int dis = 0;

        for (char c : moves){
            if (c == 'L') dis--;

            if (c == 'R') dis++;

            if (c == '_') count_++;
        }

        return abs(dis) + count_;
    }
};