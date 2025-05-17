class Solution {
public:
    void sortColors(vector<int>& nums) {
            //logic behind it is that all zeroes should be at low index , one at mid index and two at high index 
            // int low , mid , high ;
            // low = mid = 0 , high = nums.size() - 1 ;
            // for(int i = 0 ; i < nums.size() ; i++){
            //     if(nums[mid] == 0){
            //         swap(nums[low] , nums[mid]);
            //         low++ , mid++;
            //     }
            //     else if(nums[mid] == 1){
            //         mid++;
            //     }
            //     else{
            //         swap(nums[mid] , nums[high]);
            //         high-- ;
            //     }
            // }

            for(int i = 0 ; i < nums.size() - 1 ;i++){
                int minIndex = i ;
                for(int j = i+1 ; j < nums.size()  ; j++){
                    if(nums[j] < nums[minIndex]){
                        minIndex = j;
                    }
                }
                if(nums[i] > nums[minIndex]){
                    swap(nums[i] , nums[minIndex]);
                }
            }
    }
};