class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> arr ;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1 ){
                count++;
            }else{
                arr.push_back(count);
                count = 0;
            }
            if(i == nums.size() - 1){
                arr.push_back(count);
            }
        }
        int max = arr[0];
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return max;
    }
};