class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long cnt = 0;

        for(int i = max(0 , n-2*limit) ; i <= min(n , limit) ; i++){
            if(n-i > 2*limit) continue;

            int l = 0 , r = limit , ans = -1;
            while(l <= r){
                int mid = (l + r)/2;

                if(n-i-mid > limit){
                    l = mid + 1;
                }else{
                    ans = mid;
                    r = mid - 1;
                }
            }
            if(ans == -1) continue;

            // int ans = min(limit , n-i) - i;
            
            cnt += min(limit , n-i) - ans + 1;
            
        }

        return cnt;
    }
};