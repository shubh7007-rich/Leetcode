class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        int prev = 0;

        for(int i = 0 ; i < startTime.size() ; i++){
            int t = startTime[i] - prev;

            freeTime.push_back(t);

            prev = endTime[i];
        }

        freeTime.push_back(eventTime - prev);

        int i = 0 , maxi = 0 , sum = 0;
        for(int j = 0 ; j < freeTime.size() ; j++){
            sum += freeTime[j];

            while(j-i+1 > k+1){
                sum -= freeTime[i];
                i++;
            }

            maxi = max(sum , maxi);
        }

        return maxi;
    }
};