class Solution {
public:
    void func(int ind , vector<int>& nums , vector<int> &temp , set<vector<int>> & st){
        if(ind >= nums.size()){
            st.insert(temp);
            return;
        }

        temp.push_back(nums[ind]);
        func(ind+1 , nums, temp , st);
        temp.pop_back();
        func(ind+1 , nums , temp , st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        set<vector<int>> st;
        vector<int> temp;

        func(0 , nums , temp , st);

        vector<vector<int>> ans(st.begin() , st.end());
        return ans;
    }
};