class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0 , sum = 0, cnt = 0 ;

        for(int j = 0 ; j < arr.size() ; j++){
            sum += arr[j];

            if(j-i+1 == k){
                if(sum/k >= threshold){
                    cnt++;
                }

                sum -= arr[i];
                i++;
            }
        }

        return cnt;

    }
};