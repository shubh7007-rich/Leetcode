class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum1 = accumulate(apple.begin() , apple.end() , 0);

        int cnt = 0 , sum2 = 0;

        sort(capacity.rbegin() , capacity.rend());

        for(int & i : capacity){
            cnt++;

            sum2 += i;

            if(sum2 >= sum1) break;
        }

        return cnt;
    }
};