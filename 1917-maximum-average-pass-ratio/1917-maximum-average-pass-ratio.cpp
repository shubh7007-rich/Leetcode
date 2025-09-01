class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int ex) {
        using P = pair<double , int>;
        int n = classes.size();
        priority_queue<P> pq;

        for(int i = 0 ; i < n ; i++){
            int pass = classes[i][0] , total = classes[i][1];
            double ratio = (double)pass/total;
            double after = (double)(pass+1)/(total+1);
            pq.push({after - ratio , i});
        }


        while(ex--){
            auto p = pq.top();
            pq.pop();
            int i = p.second;
            classes[i][0]++;
            classes[i][1]++;
            int pass = classes[i][0] , total = classes[i][1];
            double ratio = (double)pass/total;
            double after = (double)(pass+1)/(total+1);
            pq.push({after - ratio , i});
        }
        double total = 0.0;

        for(auto vec : classes){
            int pass = vec[0] , t = vec[1];
            total += (double)pass/t;
        }

        return total/n; 
    }
};