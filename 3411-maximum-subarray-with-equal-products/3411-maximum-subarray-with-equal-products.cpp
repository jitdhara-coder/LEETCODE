
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;

        for(int i = 0; i < n - ans; i++) {

            long long prod = 1;
            int g = 0;
            int l = 1;

            for(int j = i; j < n; j++) {

                prod *= nums[j];

                if(prod > 25200)
                    break;

                g = gcd(g, nums[j]);

                l = l / gcd(l, nums[j]) * nums[j];

                if(prod == 1LL * g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
