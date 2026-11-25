class Solution {
public:
    using ll = long long;

    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    const ll BASE = 100003;

    bool check(vector<int>& nums, int k) {
        int n = nums.size();

        map<pair<ll,ll>, int> mp;

        ll h1 = 0, h2 = 0;
        ll p1 = 1, p2 = 1;

        for (int i = 0; i < k; i++) {
            h1 = (h1 * BASE + nums[i]) % MOD1;
            h2 = (h2 * BASE + nums[i]) % MOD2;

            p1 = (p1 * BASE) % MOD1;
            p2 = (p2 * BASE) % MOD2;
        }

        mp[{h1, h2}]++;

        for (int i = k; i < n; i++) {
            h1 = (h1 * BASE - nums[i-k] * p1 % MOD1 + MOD1) % MOD1;
            h1 = (h1 + nums[i]) % MOD1;

            h2 = (h2 * BASE - nums[i-k] * p2 % MOD2 + MOD2) % MOD2;
            h2 = (h2 + nums[i]) % MOD2;

            mp[{h1, h2}]++;
        }

        for (auto it : mp) {
            if (it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int low = 1, high = nums.size();
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};