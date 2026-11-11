
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        if(1LL * cost1 + cost2 <= costBoth) {
            return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }

        int both = min(need1, need2);

        long long total = 1LL * costBoth * both;

        need1 -= both;
        need2 -= both;

        if(need1 > 0) {
            total += 1LL * min(cost1, costBoth) * need1;
        }
        else if(need2 > 0) {
            total += 1LL * min(cost2, costBoth) * need2;
        }

        return total;
    }
};
