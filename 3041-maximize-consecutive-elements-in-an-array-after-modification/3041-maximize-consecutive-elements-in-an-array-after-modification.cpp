class Solution {
public:
int n;
vector<vector<int>>memo;
    int findmethod(vector<int>&nums,int start,int target){
        int j=lower_bound(nums.begin()+start,nums.end(),target)-nums.begin();

        if(j<n && nums[j]==target){
            return j;
        }
        return -1;
    }
    int solve(int i,int inc,vector<int>&nums){

        if(memo[i][inc] != -1){
            return memo[i][inc];
        }
        int currval=nums[i]+inc;
        int len=1;

        //find currval+1

        int j=findmethod(nums,i+1,currval+1);
        if(j!=-1){
            len=max(len,1+solve(j,0,nums));
        }

         j=findmethod(nums,i+1,currval);
        if(j!=-1){
            len=max(len,1+solve(j,1,nums));
        }
        return memo[i][inc]=len;

    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
       

        memo.assign(n,vector<int>(2,-1));

         int result=1;

        for(int i=0;i<n;i++){
           result = max({result, solve(i,0,nums), solve(i,1,nums)});
        }
        return result;
    }
};