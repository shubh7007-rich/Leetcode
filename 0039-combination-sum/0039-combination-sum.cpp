class Solution {
public:
    void func(int ind , int sum , vector<int>& temp , vector<int>& candidates, int target , vector<vector<int>> & ans){
        if(ind >= candidates.size()){
            if(sum == target){
                ans.push_back(temp);
            }
            return;
        }
        if(sum > target) return;

        sum += candidates[ind];
        temp.push_back(candidates[ind]);
        func(ind , sum , temp , candidates , target , ans);
        sum -= candidates[ind];
        temp.pop_back();
        func(ind+1 , sum , temp , candidates , target , ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        int sum = 0;
        
        vector<int> temp;

        func(0 , sum , temp , candidates , target , ans);

        return ans;
    }
};