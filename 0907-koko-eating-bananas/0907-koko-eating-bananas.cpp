class Solution {
public:
    bool isPos(int mid , vector<int>& piles, int h){
        int cnt = 0;

        for(int & num : piles){
            cnt += ceil((double)num/mid);

            if(cnt > h) return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 , r = 1e9 , ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(isPos(mid , piles , h)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};