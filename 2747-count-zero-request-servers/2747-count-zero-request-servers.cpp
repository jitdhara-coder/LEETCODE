
bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,int x, vector<int>& queries) {

       
            sort(logs.begin(), logs.end(), compare);

            vector<pair<int,int>> sortedQueries;

            for(int i = 0; i < queries.size(); i++) {

            sortedQueries.push_back({queries[i], i});
            
            }

        
             sort(sortedQueries.begin(), sortedQueries.end());

       
             vector<int> freq(n+1, 0);
             vector<int> ans(queries.size());

             int left = 0;
             int right = 0;
             int active = 0;

        
            for(auto &q : sortedQueries) {

            int time = q.first;
            int idx = q.second;

            int start = time - x;

           
            while(right < logs.size() &&
                  logs[right][1] <= time) {

                int server = logs[right][0];

                if(freq[server] == 0) {
                    active++;
                }

                freq[server]++;
                right++;
            }

            
            while(left < right &&
                  logs[left][1] < start) {

                int server = logs[left][0];

                freq[server]--;

                if(freq[server] == 0) {
                    active--;
                }

                left++;
            }

          
            ans[idx] = n - active;
        }

        return ans;
    }
};
