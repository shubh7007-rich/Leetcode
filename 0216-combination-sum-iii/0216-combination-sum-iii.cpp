class Solution {
public:
    void func(int start ,int sum , vector<int>& temp , vector<vector<int>>& ans , int k , int n){
        if(sum > n || temp.size() > k) return;

        if(temp.size() == k){
            if(sum == n){
                ans.push_back(temp);
            }
            return;
        }

        for(int i = start ; i <= 9 ; i++){
            temp.push_back(i);
            func(i + 1 , sum + i , temp , ans , k , n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        func(1 , 0 , temp , ans , k , n);

        return ans;
    }
}; 