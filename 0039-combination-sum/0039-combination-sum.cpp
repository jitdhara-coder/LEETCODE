class Solution {
public:
    void findcombinaion(int index, int target, vector<int>& arr,
                        vector<vector<int>>& ans, vector<int>& ds) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        if (index == arr.size() || target < 0) {
            return;
        }

       
        ds.push_back(arr[index]);
        findcombinaion(index, target - arr[index], arr, ans, ds);
        ds.pop_back();

      
        findcombinaion(index + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        findcombinaion(0, target, candidates, ans, ds);
        return ans;
    }
};