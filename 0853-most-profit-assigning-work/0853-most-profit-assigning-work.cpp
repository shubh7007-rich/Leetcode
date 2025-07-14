class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& pro, vector<int>& worker) {
        int n = diff.size() , m = worker.size() , profit = 0;
        vector<pair<int , int>> arr;

        // vector<int> maxiPro(1e5+1 , 0);

        // here do u really need to make a different array to store maximum profit till an difficulty level ? , no just in arr , just for each difficulty update its profit to maximum profit till that difficultly i.e maximum amoung all the jobs with difficulty less than equal to this difficulty

        for(int i = 0 ; i < n ; i++){
            arr.push_back({diff[i], pro[i]});
        }

        sort(arr.begin() , arr.end());

        int maxi = arr[0].second;
        // maxiPro[arr[0].first] = maxi;

        // for(int i = 1; i < n ; i++){
        //     maxi = max(maxi , arr[i].second);
        //     maxiPro[arr[i].first] = maxi;
        // }

        // update the profit for all difficulty in the arr array to maximum profit till that difficulty

        for(int i = 1; i < n ; i++){
            maxi = max(maxi , arr[i].second);
            arr[i].second = maxi;
        }


        // sort(worker.begin() , worker.end());
        // sort(diff.begin() , diff.end());

       
        // for(int & num : worker){
        //     int idx = upper_bound(diff.begin() , diff.end() , num) - diff.begin() - 1;

        //     if(idx >= 0){
        //         profit += maxiPro[diff[idx]];
        //     }
        // }

        for(int & num : worker){
            int l = 0 , r = n-1 , ans = 0;

            while(l <= r){
                int mid = l + (r-l)/2;

                if(arr[mid].first <= num){
                    ans = arr[mid].second;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }

            profit += ans;
        }

        return profit;
    }
}; 