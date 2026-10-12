class Solution {
public:

    void func(int index,vector<int>&arr,int N,vector<int>&current,vector<vector<int>>&subsetsum){
        if(index==N){
            subsetsum.push_back(current);
            return;
        }

          current.push_back(arr[index]);
          func(index+1,arr,N,current,subsetsum);
            current.pop_back();
          func(index+1,arr,N,current,subsetsum);
        

        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int N=nums.size();
        vector<vector<int>>subsetsum;
        vector<int>current;
        func(0,nums,N,current,subsetsum);
        sort(subsetsum.begin(),subsetsum.end());
        return subsetsum;

        
    }
};