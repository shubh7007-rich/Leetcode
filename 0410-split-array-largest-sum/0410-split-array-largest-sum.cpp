class Solution {
public:
    bool isPos(int mid , vector<int>& nums, int k){
        int sum = 0 , cnt = 1;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > mid) return false;
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }else{
                cnt++;
                sum = nums[i];
            }
        }

        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *min_element(nums.begin() , nums.end()) , r = accumulate(nums.begin() , nums.end() , 0);
        int ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(isPos(mid , nums , k)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};