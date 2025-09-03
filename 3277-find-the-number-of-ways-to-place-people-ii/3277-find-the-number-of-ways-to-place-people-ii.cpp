class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int cnt = 0;

        // for(auto vec : points){
        //     cout << vec[0] << " " << vec[1] << endl;
        // }

        for (int i = 0; i < points.size(); i++) {
            int y = INT_MIN;
            for (int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0],
                    y2 = points[j][1];
                bool flag = true;

                // if(x1 < x2 && y2 > y1) continue;

                if (x1 <= x2 && y1 >= y2) {
                    
                    if(y2 > y){
                        cnt++;

                        y = max(y , y2);
                    }
                }
            }
        }

        return cnt;
    }
};