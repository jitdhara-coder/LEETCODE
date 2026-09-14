class Solution {
public:
    int sumofdiv(vector<int>& arr,int div){
          int sum=0;
        for(int i=0;i<arr.size();i++){
          
            sum+=ceil((double)arr[i]/(double)div);
        }
        return sum;
    }

    
    int smallestDivisor(vector<int>& nums, int threshold) {

        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }

        int low=1, high=maxi;

        while(low<=high){

            int mid=(low+(high-low)/2);
            if(sumofdiv(nums,mid)<=threshold){
                high=mid-1;
            }

            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};