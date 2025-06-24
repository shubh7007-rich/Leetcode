class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int i = 0 , n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());

        while(i < n){
            int j = i + 3 - 1;

            if(nums[j] <= nums[i] + k){
                vector<int> temp(nums.begin() + i , nums.begin() + j + 1);
                ans.push_back(temp);
                i = j+1;
            }else{
                break;
            }

        }

        if(i == n){
            return ans;
        }

        return {};
    }
};