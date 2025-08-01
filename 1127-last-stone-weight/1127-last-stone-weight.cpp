class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin() , stones.end());

        while(pq.size() > 1){
            int t1 = 0 , t2 = 0;
            if(!pq.empty()) {
                t1 = pq.top();
                pq.pop();
            }
            if(!pq.empty()) {
                t2 = pq.top();
                pq.pop();
            }

            int diff = abs(t1 - t2);

            if(diff != 0) pq.push(diff);
        }


        if(pq.empty()) return 0;

        return pq.top();
    }
};