
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        
        int n = items.size();
        int maxFactor = 0;
        long long minPrice = LLONG_MAX;
        
        // Find maximum factor and minimum price
        for(auto &it : items) {
            maxFactor = max(maxFactor, it[0]);
            minPrice = min(minPrice, (long long)it[1]);
        }
        
        // Count frequency of each factor
        vector<int> freq(maxFactor + 1, 0);
        
        for(auto &it : items) {
            freq[it[0]]++;
        }
        
        // Count how many items each factor can generate for free
        for(int i = 1; i <= maxFactor; i++) {
            for(int j = 2 * i; j <= maxFactor; j += i) {
                freq[i] += freq[j];
            }
        }
        
        // Sort items by price
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        long long ans = 0;
        long long rem = budget;
        
        // Buy bonus copies first
        for(auto &it : items) {
            
            int factor = it[0];
            long long price = it[1];
            
            // Not profitable compared to two cheapest normal copies
            if(price >= 2 * minPrice) {
                break;
            }
            
            int gain = freq[factor] - 1;
            
            if(gain <= 0) {
                continue;
            }
            
            long long take = min((long long)gain, rem / price);
            
            ans += 2 * take;
            rem -= take * price;
        }
        
        // Spend remaining budget on cheapest item
        ans += rem / minPrice;
        
        return (int)ans;
    }
};
