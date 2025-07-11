class Solution {
public:
    bool isPos(int mid , vector<int>& nums, vector<vector<int>>& queries){
        int ind = mid - 1 , n = nums.size();

        vector<int> diff(n+1 , 0);

        for(int i = 0 ; i <= ind  ; i++){
            int idx1 = queries[i][0] , idx2 = queries[i][1] , val = queries[i][2];

            diff[idx1] += val;
            diff[idx2 + 1] -= val; 
        }

        for(int i = 1 ; i <= n ; i++) diff[i] += diff[i-1];

        for(int i = 0 ; i < n ; i++){
            if(nums[i] > diff[i]) return false;
        }

        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int l = 0 , r = queries.size()  , ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(isPos(mid , nums , queries)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};