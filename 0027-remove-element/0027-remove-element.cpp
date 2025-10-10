class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;

        for(int i : nums){
            if(i == val) cnt++;
        }

        for(int i = 0 ; i < nums.size() - cnt; i++){
            int j = i+1;
            while(j < nums.size() && nums[i] == val){
                swap(nums[i] , nums[j]);
                j++;
            }
        }

        return nums.size() - cnt;
    }
};