class Solution {
public:
    void rev(int l , int r , vector<int>& nums){
        while(l <= r){
            swap(nums[l] , nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
    /*
        [1 , 2, 3, 4 , 5 , 6 , 7]

        [4 , 3, 2, 1 , 7 , 6 , 5]

        [5 , 6 , 7 , 1 , 2, 3, 4]

        [-1 , -100 , 3 , 99]

        [3 , -100 , -1 , 99 , 3]

        [99 , -1 , -100 , 3]
    
    */

    if(nums.size() == 1)  return;
    k = k % nums.size();

    rev(0 , nums.size() - 1 , nums);
    rev(0 , k-1 , nums);
    rev(k , nums.size() - 1 , nums);


    }
};