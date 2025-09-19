class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arr, int w, int m) {
        int cnt = 0 , i = 0;

        unordered_map<int , int> mp;

        // unordered_map<int , bool> canDiscard;

        vector<bool> discard(1e5+1 , false);

        for(int j = 0 ; j < arr.size() ; j++){
            while(i < j && j-i+1 > w){
                if(!discard[i]){
                    mp[arr[i]]--;
                    if(mp[arr[i]] == 0){
                        mp.erase(arr[i]);
                    }
                }
                i++;
            }
            
            if(mp[arr[j]] + 1 > m){
                discard[j] = true;
                cnt++;
            }else{
                mp[arr[j]]++;
            }

            
        }

        return cnt;
    }
};