class Solution {
public:
    bool isPos(int diff , vector<int>& price, int k){
        int cnt = 1 , prev = price[0];

        for(int i = 1; i < price.size() ; i++){
            if(price[i] - prev >= diff){
                cnt++;
                prev = price[i];
            }

            if(cnt >= k) return true;
        }

        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin() , price.end());
        int l = 0 , r = 1e9 , ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(isPos(mid , price , k)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return ans;
    }
};