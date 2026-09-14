class Solution {
public:

    int find_days(vector<int>& weight,int capacity){
        
        int day=1,load=0;

        for(int i=0;i<weight.size();i++){

            if(weight[i]+load>capacity){
                day=day+1;
                load=weight[i];
            }
            else{
                load+=weight[i];
            }
        }
        return day;

    }




    int shipWithinDays(vector<int>& weights, int days) {
       int low=*max_element(weights.begin(),weights.end());
       int high=accumulate(weights.begin(),weights.end(),0);

       while(low<=high){
        int mid=(low+(high-low)/2);

        int number_of_days=find_days(weights,mid);

        if(number_of_days<=days){
            high=mid-1;
        }
        else{

            low=mid+1;
        }
       }
       return low;

    }
};