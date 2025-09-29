class Solution {
public:
    void func(int ind, int k, int n, int sum, vector<int>& temp,
              vector<vector<int>>& ans, vector<int>& nums) {
        if (sum > n || temp.size() > k)
            return;
        if (ind >= nums.size()) {
            if (temp.size() == k && sum == n) {
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(nums[ind]);
        sum += nums[ind];

        func(ind + 1, k, n, sum, temp, ans, nums);

        sum -= nums[ind];
        temp.pop_back();

        func(ind + 1, k, n, sum, temp, ans, nums);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> nums;

        for (int i = 1; i <= 9; i++)
            nums.push_back(i);

        func(0, k, n, 0, temp, ans, nums);

        return ans;
    }
};