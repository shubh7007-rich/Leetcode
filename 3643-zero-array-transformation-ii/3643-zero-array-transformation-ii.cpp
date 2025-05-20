class Solution {
public:
    bool isPos(int mid , vector<int>& nums, vector<vector<int>>& q , int n){
        vector<int> diff(n+1 , 0);

        for(int i = 0 ; i < mid ; i++){

            diff[q[i][0]] += q[i][2];
            diff[q[i][1] + 1] -= q[i][2];
        }

        for(int i = 1 ; i < n+1 ; i++){
            diff[i] += diff[i-1];
        }

        for(int i = 0 ; i < n ; i++){
            if(nums[i] > diff[i]) return false;
        }

        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int l = 0 , r = q.size() , ans = -1 , n = nums.size();

        while(l <= r){
            int mid = l + (r-l)/2;

            if(isPos(mid , nums , q , n)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};