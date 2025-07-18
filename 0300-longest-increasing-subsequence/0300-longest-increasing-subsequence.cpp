class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> lis(n , INT_MAX);

        for(int & i : nums){
            int idx = lower_bound(lis.begin() , lis.end() , i) - lis.begin();

            lis[idx] = i;
        }

        int cnt = 0;

        for(int & i : lis){
            if(i == INT_MAX) break;
            cnt++;
        }

        return cnt;
    }
};