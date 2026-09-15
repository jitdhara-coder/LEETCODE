class Solution {
public:

    bool can_we_place(vector<int>& basket,int posi,int ball){

        int n=basket.size();

        int count_balls=1,last=basket[0];

        for(int i=0;i<n;i++){
            if(basket[i]-last>=posi){
                count_balls++;
                last=basket[i];
            }

            if(count_balls>=ball){
                return true;

            }

        }
        return false;

    }



    int maxDistance(vector<int>& position, int m) {

        int n=position.size();

        sort(position.begin(),position.end());

        int low=1,high=position[n-1]-position[0];

        while(low<=high){
            int mid=(low+(high-low)/2);

            if(can_we_place(position,mid,m)==true){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};