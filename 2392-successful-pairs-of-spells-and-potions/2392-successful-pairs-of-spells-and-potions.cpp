#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        /*
            a * b >= success
            a >= sucess/b

            5 * b >= 7
            b >= 7/5
        */

        int size = potions.size();
        sort(potions.begin() , potions.end());
        vector<int> ans;
        for(int i : spells){
            ll upr = ceil((double)success/i);

            int idx = lower_bound(potions.begin() , potions.end(), upr) - potions.begin();

            ans.push_back(potions.size() - idx);
        }

        return ans;
    }
};