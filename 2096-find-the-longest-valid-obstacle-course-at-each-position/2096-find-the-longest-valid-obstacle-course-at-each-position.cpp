class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        int n = obs.size();

        vector<int> mx(n , INT_MAX);

        int cnt = 0;
        vector<int> ans(n , 1);

        for(int i = 0 ; i < n ; i++){
            int ind = upper_bound(mx.begin() , mx.end(), obs[i]) - mx.begin();

            mx[ind] = obs[i];

            ans[i] = ind+1;
        }

        return ans;
    }
};