class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // approach 1 - sorting , t.c - O(n * log(n))
        // approach 2 - total sum from 0 to n - sum of  array elements , O(n)

        // approach 3 - Cyclic sort 

        // cyclic sort 
        int i = 0;

        while(i < nums.size()){
            int correct = nums[i];
            if(correct < nums.size() && (nums[i] != i)){
                swap(nums[i] , nums[correct]);
            }else{
                i++;
            }
        }

        for(int i = 0; i < nums.size() ; i++){
            if(i != nums[i])return i;
        }

        return nums.size();
        
    }
};