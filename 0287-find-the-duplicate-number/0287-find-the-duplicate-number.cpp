class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        
        [1 , 3 , 4 , 2 , 2]

        Approach 1 -> O(n*n)

        Approach 2 -> O(n * logn)  -> when arr[i] == arr[i+1] then arr[i] will be duplicate

        Approach 3 -> O(n) + O(n)

        Approach 3 ->

        [1 , n] --> and the size if n+1 , so all the numbers are valid index

        i can perform a cyclic sort and if the nums[i] != i+1 then that number will be duplicate

        */

        int i = 0;
        while(i < nums.size()){
            int correct = nums[i] - 1;

            if(nums[i] != nums[correct]){
                swap(nums[i] , nums[correct]);
            }else{
                i++;
            }
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != i+1) return nums[i];
        }

        return -1;


    }
};