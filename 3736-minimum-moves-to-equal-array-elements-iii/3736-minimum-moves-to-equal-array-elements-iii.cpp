class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int maxi = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }

        return (maxi * nums.size()) - sum;
    }
};