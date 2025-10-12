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

    */
    int trap(vector<int>& height) {
        int n = height.size();

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

        for(int & i : trappedWater) sum += i;

        return sum;
    }
};