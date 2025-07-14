class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& pro, vector<int>& worker) {
        int n = diff.size() , m = worker.size() , profit = 0;
        vector<pair<int , int>> arr;

        vector<int> maxiPro(1e5+1 , 0);

        for(int i = 0 ; i < n ; i++){
            arr.push_back({diff[i], pro[i]});
        }

        sort(arr.begin() , arr.end());

        int maxi = arr[0].second;
        maxiPro[arr[0].first] = maxi;

        for(int i = 1; i < n ; i++){
            maxi = max(maxi , arr[i].second);
            maxiPro[arr[i].first] = maxi;
        }


        sort(worker.begin() , worker.end());
        sort(diff.begin() , diff.end());

       
        for(int & num : worker){
            int idx = upper_bound(diff.begin() , diff.end() , num) - diff.begin() - 1;

            if(idx >= 0){
                profit += maxiPro[diff[idx]];
            }
        }

        return profit;
    }
}; 