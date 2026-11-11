class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long type1 = 
            1LL * need1 * cost1 +
            1LL * need2 * cost2;


        long long type2 =
            1LL * min(need1, need2) * costBoth +
            1LL * (need1 - min(need1, need2)) * cost1 +
            1LL * (need2 - min(need1, need2)) * cost2;

        long long type3 = 1LL * max(need1, need2) * costBoth;

        return min({type1, type2, type3});
    }
};