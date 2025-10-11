class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n = num.size();
        int l = 0 , r = n - 1;

        while(l < r){
            if(num[l] + num[r] > target){
                r--;
            }else if(num[l] + num[r] < target){
                l++;
            }else{
                return {l+1 , r+1};
            }
        }
        return {-1 , -1};
    }
};