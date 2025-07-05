class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501 , 0);

        for(int & i : arr) freq[i]++;

        int maxi = -1;

        for(int i = 1 ; i < 501 ; i++){
            if(freq[i] == i){
                maxi = i;
            }
        }

        return maxi;
    }
};