class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>available_server;
        for(int i=0;i<k;i++){
            available_server.insert(i);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> busy_server;//{finishinf time,server id}

        vector<int>count_request(k,0);
        for(int i=0;i<arrival.size();i++){
            int time=arrival[i];
            while(!busy_server.empty() && busy_server.top().first<=time){
                int server=busy_server.top().second;
                busy_server.pop();
                available_server.insert(server);
            }
            int target=i%k;
            auto it=available_server.lower_bound(target);
            if(it==available_server.end()){
                it=available_server.begin();
            }
            if(available_server.empty()){
                continue;
            }
            int target_server=*it;

            available_server.erase(it);

            busy_server.push({time+load[i],target_server});

            count_request[target_server]++;
        }

        int max_number_of_req=*max_element(begin(count_request),end(count_request));

        vector<int>result;
        for(int i=0;i<k;i++){
            if(count_request[i]==max_number_of_req){
                result.push_back(i);
            }
        }
        return result;
    }
};