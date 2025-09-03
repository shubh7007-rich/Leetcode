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
            for (int j = i + 1; j < points.size(); j++) {

                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0],
                    y2 = points[j][1];
                bool flag = true;

                // if(x1 < x2 && y2 > y1) continue;

                if (x1 <= x2 && y1 >= y2) {
                    for (int k = i; k < j; k++) {
                        if (k != i && k != j) {
                            int x3 = points[k][0], y3 = points[k][1];
                            if (x3 >= x1 && x3 <= x2 && y3 >= min(y1, y2) &&
                                y3 <= max(y2, y1)) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag)
                        cnt++;
                }
            }
        }

        return cnt;
    }
};