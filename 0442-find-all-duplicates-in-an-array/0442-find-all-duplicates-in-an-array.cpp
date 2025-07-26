class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // each integer can appear atmost twice 
        // [1 , n] -- so every number can form a valid index , nums[i] - 1

        // so here as numbers are from 1 to n , so i can use cyclic sort to sort the array 
        // and the position at which nums[i] != i+1 , then nums[i] is duplicate

        vector<int> duplicates;
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
            if(nums[i] != i+1){
                duplicates.push_back(nums[i]);
            }
        }

        return duplicates;
    }
}; 