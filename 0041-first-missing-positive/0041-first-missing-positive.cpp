class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
            sort()
        
        */

        sort(nums.begin() , nums.end());

        int p = 1;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < p) continue;
            if(p != nums[i]){
                return p;
            }
            p++;
        }

        return p;
    }
};