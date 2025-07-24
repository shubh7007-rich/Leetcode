class Solution {
public:
    // void merge(int lb , int mid , int ub , vector<int>& nums){
    //     vector<int> temp;
    //     int p1 = lb , p2 = mid + 1;

    //     while(p1 <= mid && p2 <= ub){
    //         if(nums[p1] <= nums[p2]){
    //             temp.push_back(nums[p1]);
    //             p1++;
    //         }else{
    //             temp.push_back(nums[p2]);
    //             p2++;
    //         }
    //     }

    //     while(p1 <= mid){
    //         temp.push_back(nums[p1]);
    //         p1++;
    //     }
    //     while(p2 <= ub){
    //          temp.push_back(nums[p2]);
    //          p2++;
    //     }
    //     int p3 = 0;

    //     for(int i = lb ; i <= ub ; i++){
    //         nums[i] = temp[i - lb];
    //     }
    // }
    // void mergeS(int lb , int ub , vector<int>& nums){
    //     if(lb < ub){
    //         int mid = (lb + ub)/2;

    //         mergeS(lb , mid , nums);
    //         mergeS(mid+1 , ub , nums);
    //         merge(lb , mid , ub , nums);
    //     }
    // }
    void sortColors(vector<int>& nums) {
        int lb = 0 , ub = nums.size() - 1;
        // mergeS(lb , ub , nums);

        int low = 0 , mid = 0 , high = ub;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid] , nums[low]);
                low++;mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[high] , nums[mid]);
                high--;
            }
        }



    }
};