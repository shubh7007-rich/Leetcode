#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happ, int k) {
        ll ans = 0 , c = 0;

        sort(happ.rbegin() , happ.rend());

        for(int i = 0 ; i < happ.size() ; i++){
            if(happ[i] - c <= 0) break;
            if(k == 0)break;
            ans += happ[i] - c;
            c++;k--;
        }

        return ans;
    }
};