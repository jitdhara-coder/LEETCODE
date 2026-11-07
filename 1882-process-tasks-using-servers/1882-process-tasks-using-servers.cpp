
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> available;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> busy;

        
        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);

        long long time = 0;

        for(int j = 0; j < m; j++) {

            time = max(time, (long long)j);

           
            while(!busy.empty() && busy.top().first <= time) {

                int idx = busy.top().second;

                busy.pop();

                available.push({servers[idx], idx});
            }

           
            if(available.empty()) {

                time = busy.top().first;

               
                while(!busy.empty() && busy.top().first <= time) {

                    int idx = busy.top().second;

                    busy.pop();

                    available.push({servers[idx], idx});
                }
            }

           
            int weight = available.top().first;
            int idx = available.top().second;

            available.pop();

            ans[j] = idx;

          
            busy.push({time + tasks[j], idx});
        }

        return ans;
    }
};
