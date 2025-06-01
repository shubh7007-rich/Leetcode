class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        vector<vector<int>> arr;
        for(int i = 0 ; i <= (1<<n) ; i++){
            int num = i;
            unordered_set<int> temp;
            for(int j = 0 ; j < n ; j++){
                if(num & (1<<j)){
                    temp.insert(j);
                }
            }
            long long prod1 = 1 , prod2 = 1;
            for(int j = 0 ; j < n ; j++){
                if(temp.find(j) == temp.end()){
                    if(prod1 > target) break;
                    prod1 *= nums[j];
                }else{
                    if(prod2 > target) break;
                    prod2 *= nums[j];
                }
            }

            if(prod1 == target && prod2 == target) return true;

        }

        return false;

        
    }
};