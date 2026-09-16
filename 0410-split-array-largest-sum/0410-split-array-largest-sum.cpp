class Solution {
public:
    int sub_array(vector<int>& arr,int m){
        int sub=1,value=0;

        int n=arr.size();

        for(int i=0;i<n;i++){

            if(value+arr[i]<=m){
                value+=arr[i];
            }

            else{
                sub++;
                value=arr[i];
            }
        }
        return sub;
    }

    int splitArray(vector<int>& nums, int k) {

        int n=nums.size();

        int low=*max_element(nums.begin(),nums.end());

        int high=accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid=(low+(high-low)/2);

         int subarrays=sub_array(nums,mid);

         if(subarrays>k){
            low=mid+1;
         }
         else{
            high=mid-1;
         }
        }
        return low;
        
    }
};