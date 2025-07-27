class Solution {
public:
    void func(int ind , int sum , vector<int>& temp , vector<int>& candidates, int target , set<vector<int>> & ans){
        if(ind >= candidates.size()){
            if(sum == target){
                ans.insert(temp);
            }
            return;
        }
        if(sum > target) return;

        sum += candidates[ind];
        temp.push_back(candidates[ind]);
        func(ind + 1 , sum , temp , candidates , target , ans);
        sum -= candidates[ind];
        temp.pop_back();
        while(ind + 1 < candidates.size() && (candidates[ind] == candidates[ind+1])){
            ind++;
        }
        func(ind+1 , sum , temp , candidates , target , ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        sort(candidates.begin() , candidates.end());
        int sum = 0;
        
        vector<int> temp;

        func(0 , sum , temp , candidates , target , ans);

        vector<vector<int>> yo(ans.begin() , ans.end());

        return yo;
    }
};
