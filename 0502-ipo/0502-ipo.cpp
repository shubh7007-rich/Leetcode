class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // vector<pair<int , int>> arr;
        vector<pair<int , int>> arr;
        int n = capital.size() , pro = 0;
        int intial = w;

        priority_queue<int> pq;

        for(int i = 0 ; i < n ; i++){
            arr.push_back({capital[i] , profits[i]});
        }
        sort(arr.begin() , arr.end());

        int p = 0;
        while(k--){
            while(p < arr.size() && arr[p].first <= w){
                pq.push(arr[p].second);
                p++;
            }
            if(!pq.empty()){
                pro += pq.top();
                w += pq.top();
                pq.pop();
            } 
        }

        return pro + intial;
    }
};