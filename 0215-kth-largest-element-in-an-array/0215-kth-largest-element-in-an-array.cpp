class Solution {
public:
    int partition(int L , int R , vector<int>& nums){
        int i = L+1 , j = R;
        int pivot = L;

        while(i <= j){
            if(nums[i] < nums[pivot] && nums[j] > nums[pivot]){
                swap(nums[i] , nums[j]);
                i++;
                j--;
            }

            if(nums[i] >= nums[pivot]) i++;
            if(nums[j] <= nums[pivot]) j--;
        }

        swap(nums[pivot] , nums[j]);

        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {

        int L = 0 , R = nums.size() - 1 , pivot_Idx = 0;

        while(true){
            
            pivot_Idx = partition(L , R , nums);

            if(pivot_Idx == k-1){
                break;
            }

            if(pivot_Idx > k-1) R = pivot_Idx - 1;

            if(pivot_Idx < k-1) L = pivot_Idx + 1;
        }

        return nums[pivot_Idx];
    }
};