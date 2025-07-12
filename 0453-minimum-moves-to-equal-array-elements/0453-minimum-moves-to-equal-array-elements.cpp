#define ll long long

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int x = *min_element(nums.begin(), nums.end());
        priority_queue<int> pq(nums.begin(), nums.end());
        int moves = 0;
        while (pq.top() > x) {
            int t1 = pq.top();
            pq.pop();
            moves += abs(t1-x);
        }  

        return  moves;
    }
};