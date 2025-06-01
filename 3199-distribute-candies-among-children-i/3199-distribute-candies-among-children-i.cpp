class Solution {
public:
    int distributeCandies(int n, int limit) {
        int cnt = 0;

        for(int i = 0 ; i <= min(n , limit) ; i++){
            if(n-i > 2*limit) continue;

            for(int j = 0 ; j <= min(limit , n-i) ; j++){
                int k = n-i-j;

                if(k > limit) continue;

                cnt++;
            }
        }

        return cnt;
    }
};