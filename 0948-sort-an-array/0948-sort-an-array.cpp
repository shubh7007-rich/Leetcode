class Solution {
public:
    void merge(int lb , int mid , int ub , vector<int>& nums){
        vector<int> temp;

        int l = lb , r = mid + 1;

        while(l <= mid && r <= ub){
            if(nums[l] <= nums[r]){
                temp.push_back(nums[l]);
                l++;
            }else{
                temp.push_back(nums[r]);
                r++;
            }
        }
        while(l <= mid ){
            temp.push_back(nums[l]);
            l++;
        }
        while(r <= ub){
            temp.push_back(nums[r]);
            r++;  
        }

        for(int k = lb ; k <= ub ; k++){
            nums[k] = temp[k - lb];
        }
    }
    void mergeSort(int lb , int ub , vector<int>& nums){
        if(lb >= ub) return;

        int mid = (lb + ub) / 2;

        mergeSort(lb , mid , nums);
        mergeSort(mid+1 , ub , nums);
        merge(lb , mid , ub , nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        /*
            merge sort -->  
                    0    1   2   3   4    5   6
                    [1 , 2 , 3 , 4 , 5 , 6 , 7]

                    n = 7 , mid = 7/2 --> 3

                    0    1   2   3     4   5   6
                    [1 , 3 , 5 , 7]   [2 , 4 , 6]

                [3, 7]   [1 , 5]      [2 , 4]   [6]

                [7] [3]   [5]  [1]   [2]    [4]   

                t.c -->O(n log n)
 
        */

       mergeSort(0 , nums.size() - 1 , nums);


        return nums;
    }
};