
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = LLONG_MAX / 4;

        // Two multisets to maintain the median
        multiset<long long> low, high;

        long long sumLow = 0, sumHigh = 0;

        // Maintain low with (x+1)/2 elements
      auto rebalance = [&]() {
    int target = (low.size() + high.size() + 1) / 2;

    while (low.size() > target) {
        auto it = prev(low.end());
        long long val = *it;

        low.erase(it);
        sumLow -= val;

        high.insert(val);
        sumHigh += val;
    }

    while (low.size() < target) {
        auto it = high.begin();
        long long val = *it;

        high.erase(it);
        sumHigh -= val;

        low.insert(val);
        sumLow += val;
    }
};

        auto add = [&](long long val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }

            rebalance();
        };

        auto remove = [&](long long val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            rebalance();
        };

        // Calculate minimum cost for a window
        auto getCost = [&]() -> long long {
            long long median = *low.rbegin();

            long long leftCost =
                median * (long long)low.size() - sumLow;

            long long rightCost =
                sumHigh - median * (long long)high.size();

            return leftCost + rightCost;
        };

        // Step 1: Calculate cost of every window
        int m = n - x + 1;
        vector<long long> cost(m);

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = 1; i < m; i++) {
            remove(nums[i - 1]);
            add(nums[i + x - 1]);

            cost[i] = getCost();
        }

        // Step 2: DP to select k non-overlapping windows
        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Don't select a window ending here
                curr[i] = curr[i - 1];

                // Select the window [i-x, i-1]
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
