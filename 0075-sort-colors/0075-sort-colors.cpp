class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            [2 , 0 , 2 , 1, 1 , 0]

            1st pass --> 
            [0 , 2 , 2 , 1, 1, 0]
            [0 , 2,  2, 1, ,1 , 0]
            [0 , 2,  1, 2, ,1 , 0]
            [0 , 2,  1, 1, ,2 , 0]
            [0 , 2,  1, 1, ,0 , 2]

            2nd pass  -->
            [0 , 2,  1, 1, ,0 , 2]
            [0 , 1,  2, 1, ,0 , 2]
            [0 , 1,  1, 2, ,0 , 2]
            [0 , 1,  1, 0, ,2 , 2]
            [0 , 1,  1, 0, 2 , 2]
            

            
        */

        // bubble sort --> O(n^2)

        for(int i = 0 ; i < nums.size()-1; i++){
            bool swapped = false;
            for(int j = 0 ; j < nums.size() - i - 1 ; j++){
                if(nums[j] > nums[j+1]){
                    swap(nums[j] , nums[j+1]);
                    swapped = true;
                }
            }
            if(!swapped) break;
        }

        // merge sort --> O(n logn)

        // low mid high , low points to 0 , mid points to 1 , high points to 2
    }
};