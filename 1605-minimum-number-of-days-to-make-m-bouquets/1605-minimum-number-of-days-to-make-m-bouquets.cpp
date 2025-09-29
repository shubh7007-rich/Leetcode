#define ll long long
class Solution {
public:
    bool isPos(int days , vector<int>& bloomDay, int m, int k ){
        ll cnt = 0 , c = 0;
        for(int i = 0 ; i < bloomDay.size() ; i++){
            if(bloomDay[i] > days){
                c = 0;
            }else{
                c++;
            }
            if(c == k){
                c = 0;
                cnt++;
            }

            if(cnt >= m) return true;
        
        }

        return false;
    }
    //                    mini ........ x-3  x-2  x-1 x x+1               maxi
    int minDays(vector<int>& bloomDay, int m, int k) {
        // brute force
        int n = bloomDay.size();
        if(m *1ll* k  > n) return -1;

        // t.c --> 1e9 * 1e5
        // ll total = m*k;
        // sort(bloomDay.begin() , bloomDay.end());
        int mini = *min_element(bloomDay.begin() , bloomDay.end()) , maxi = *max_element(bloomDay.begin() , bloomDay.end());

        int l = mini , r = maxi , ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(isPos(mid , bloomDay , m , k)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};