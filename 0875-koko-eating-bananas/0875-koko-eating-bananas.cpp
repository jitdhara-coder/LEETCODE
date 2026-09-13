class Solution {
public:
    long long findmax(vector<int> &v){
        long long maxi=LLONG_MIN;
        int n=v.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,(long long)v[i]);

        }
        return maxi;
    }  

    long long calculate_total_hours(vector<int> &v,long long hourly){

         long long total_hours=0;
        int n=v.size();

        for(int i=0;i<n;i++){
            total_hours+=ceil((v[i]+hourly-1)/hourly);
        }
        return total_hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        long long low=1,high=findmax(piles);

        while(low<=high){

            long long mid=(low+(high-low)/2);

             long long total_hours=calculate_total_hours(piles,mid);

             if(total_hours<=h){
                high=mid-1;
             }
             else{
                low=mid+1;
             }
        }
        return (int)low;
        
    }
};