
class Solution {
public:
    int n;
    string str;

    vector<vector<int>> memo;
    vector<vector<int>> costMemo;

    // Calculate minimum changes for substring [i...j]
    int getCost(int i, int j) {
        int len = j - i + 1;

        if (costMemo[i][j] != -1) {
            return costMemo[i][j];
        }

        int minCost = INT_MAX;

        // Try every valid divisor
        for (int d = 1; d < len; d++) {

            if (len % d != 0)
                continue;

            int cost = 0;

            // Check all d groups
            for (int group = 0; group < d; group++) {

                int l = i + group;
                int r = l + (len / d - 1) * d;

                while (l < r) {

                    if (str[l] != str[r])
                        cost++;

                    l += d;
                    r -= d;
                }
            }

            minCost = min(minCost, cost);
        }

        return costMemo[i][j] = minCost;
    }

    // Partition remaining string into k parts
    int solve(int start, int k) {

        if (k == 0) {
            if (start == n)
                return 0;

            return INT_MAX;
        }

        if (start + 2 * k > n)
            return INT_MAX;

        if (memo[start][k] != -1)
            return memo[start][k];

        int result = INT_MAX;

        for (int end = start + 1; end < n; end++) {

            int remainingCost = solve(end + 1, k - 1);

            if (remainingCost == INT_MAX)
                continue;

            int currentCost = getCost(start, end);

            result = min(result,
                         currentCost + remainingCost);
        }

        return memo[start][k] = result;
    }

    int minimumChanges(string s, int k) {

        str = s;
        n = s.size();

        memo.assign(n + 1, vector<int>(k + 1, -1));

        costMemo.assign(n, vector<int>(n, -1));

        return solve(0, k);
    }
};
