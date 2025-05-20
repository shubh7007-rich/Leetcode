class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> diff(n+1 , 0);

        for(vector<int>& vec : q){
            diff[vec[0]]++;
            diff[vec[1] + 1]--;
        }

        for(int i = 1 ; i < n+1 ; i++){
            diff[i] += diff[i-1];
        }

        for(int i = 0 ; i < n ; i++){
            if(diff[i] < nums[i]) return false;
        }

        return true;
    }
};