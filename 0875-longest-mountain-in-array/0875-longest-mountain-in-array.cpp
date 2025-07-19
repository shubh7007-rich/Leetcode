class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxi = 0;
        if(arr.size() == 1) return 0;

        for(int i = 0 ; i < arr.size() ; i++){
            int l = i-1 , r = i+1, top = arr[i];
            bool flag1 = false , flag2 = false;

            while(l >= 0 && arr[l] < top){
                top = arr[l];
                l--;
                flag1 = true;
            }
            top = arr[i];

            while(r < arr.size() && arr[r] < top){
                top = arr[r];
                r++;
                flag2 = true;
            }

            if(flag1 && flag2){
                maxi = max(maxi , r-l-1);
            }
        }

        return maxi;
    }
};