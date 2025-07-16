class Solution {
public:
    int maximumLength(vector<int>& nums) {
        /* % 2 so we can get either 0 or 1 
         0 ---> our sum every two elements needs to be even -->
                so for this case , we need all odd or all even
         1 --> our sum needs to be odd -->
                so for this case , either even odd or odd even

         */

        int l1 = 0 , l2 = 0 , l3 = 0 , l4 = 0;

        // all odds

        for(int & i : nums){
            if(i&1) l1++;
        }

        // all even
        for(int & i : nums){
            if(!(i&1)) l2++;
        }

        // even odd
        bool flag = true;

        for(int & i : nums){
            if(flag){  // even
                if(!(i&1)){
                    l3++;
                    flag = !flag;
                }
                
            }else{  // odd
                if(i&1){
                    l3++;
                    flag = !flag;
                }
                
            }
        }

        // odd even
        flag = true;

        for(int & i : nums){
            if(flag){  // odd
                if(i&1){
                    l4++;
                    flag = !flag;
                }
                
            }else{  // even
                if(!(i&1)){
                    flag = !flag;
                    l4++;
                }
                
            }
        }


        return max({l1 , l2 , l3 , l4});

    }
};