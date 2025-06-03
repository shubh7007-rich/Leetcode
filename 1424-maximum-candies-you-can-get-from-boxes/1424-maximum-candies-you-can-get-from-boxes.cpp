class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0 , n = status.size();

        queue<int> que;

        unordered_set<int> fK , fB;    // found keys , found Boxes

        vector<int> vis(n , 0);

        for(int & i : initialBoxes){
            
            if(status[i]) {que.push(i);vis[i] = 1;}
            fB.insert(i);
        }

        while(!que.empty()){
            int size = que.size();

            while(size--){
                int fro = que.front();
                que.pop();
                ans += candies[fro];
                // vis[fro] = 1;

                for(auto & k : keys[fro]){
                    fK.insert(k);
                }
                for(auto & b : containedBoxes[fro]){
                    fB.insert(b);
                }

                for(auto & b : fB){
                    if(!vis[b]){
                        if(status[b] || (fK.find(b) != fK.end())){
                            que.push(b);
                            vis[b] = 1;
                        }
                    }
                }
            }
        }

        return ans;

    }
};