class Solution {
public:
    void func(int ind , vector<int>& nums , vector<int> &temp , vector<vector<int>> & st){
        if(ind >= nums.size()){
            st.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        func(ind+1 , nums, temp , st);
        temp.pop_back();
        while(ind+1 < nums.size() && nums[ind] == nums[ind+1]) ind++;
        func(ind+1 , nums , temp , st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> st;
        vector<int> temp;

        func(0 , nums , temp , st);

        vector<vector<int>> ans(st.begin() , st.end());
        return ans;
    }
};