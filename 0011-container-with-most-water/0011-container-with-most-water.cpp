class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxi = 0;

        int l = 0 , r = n - 1;

        while(l <= r){
            maxi = max(maxi , min(height[l] , height[r]) * (r-l));

            if(height[r] >= height[l]){
                l++;
            }else{
                r--;
            }
        }

        return maxi;
    }
};