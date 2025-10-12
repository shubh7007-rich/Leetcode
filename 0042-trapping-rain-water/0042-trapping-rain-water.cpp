class Solution {
public:
    /*
        height --> [0,1,0,2,1,0,1,3,2,1,2,1]
            
        min(LMax , RMax) - height[i]

        (1 , 3) - 0 = 1

        (1 , 3) - 2 = -1  --> 0

        (2 , 3) - 1 = 1

        (2 , 3) - 0 = 2

        (2 , 3) - 1 = 1

        (2 , 2) - 3 = -1 --> 0

        (3 , 2) - 2 = 0

        (3 , 2) - 1 = 1

        (3 , 1) - 2 = -1


        units --> 6
        
        for every index we need leftMax and RightMax

        Better Approach -->

        vector<int> lMax(n , 0) , rMax(n , 0);

        int l = height[0];

        for(int i = 1 ; i < n ; i++){
            lMax[i] = l;

            l = max(l , height[i]);
        }

        int r = height[n-1];

        for(int i = n-2 ; i >= 0 ; i--){
            rMax[i] = r;

            r = max(r , height[i]);
        }

        vector<int> trappedWater(n , 0);

        for(int i = 1 ; i < n-1 ; i++){
            trappedWater[i] = max(0 , min(lMax[i] , rMax[i]) - height[i]);
        }

        int sum = 0;

        for(int i : trappedWater) sum += i;

    */

    int trap(vector<int>& height) {
        int n = height.size();

        int lMax = height[0] , rMax = height[n-1];

        vector<int> trappedWater(n , 0);

        int l = 1 , r = n-2;

        while(l <= r){
            if(lMax <= rMax){
                trappedWater[l] = max(0 , lMax - height[l]);
                lMax = max(lMax , height[l]);
                l++;
            }else{
                trappedWater[r] = max(0 , rMax - height[r]);
                rMax = max(rMax , height[r]);
                r--;
            }
        }

        int sum = 0;

        for(int i : trappedWater) sum += i;

        // cout << sum << endl;

        return sum;


    }
};