class Solution {
public:
    int partition(int l , int r , vector<int>& unique , unordered_map<int , int> & freq){
        int pivotElem = unique[l];
        int pivotFreq = freq[pivotElem];

        int i = l+1 , j = r;

        while(i <= j){
            if(freq[unique[i]] < freq[unique[l]] && freq[unique[j]] >= freq[unique[l]]){
                swap(unique[i] , unique[j]);
                j--;
                i++;
            }

            if(freq[unique[i]] >= freq[unique[l]]){
                i++;
            }

            if(freq[unique[j]] < freq[unique[l]]){
                j--;
            }
        } 

        swap(unique[j] , unique[l]);

        return j;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Approach 1 -- O(nlogn)
        // unordered_map<int , int> freq;

        // for(int & i : nums) freq[i]++;  // O(n)

        // priority_queue<pair<int , int>> pq;

        // for(auto [num , freq] : freq){    // O(n)
        //     pq.push({freq , num});      
        // }

        // // O(nlogn)

        // vector<int> ans;

        // while(k--){
        //     if(!pq.empty()){
        //         ans.push_back(pq.top().second);
        //         pq.pop();
        //     } 
        // }

        // return ans;

        // Approach 2 --> QuickSelect

        int n = nums.size();

        unordered_map<int , int> freq;

        for(int & i : nums) freq[i]++;

        vector<int> unique , ans;

        for(auto p : freq){
            unique.push_back(p.first);
        }

        int l = 0 , r = unique.size()-1;
    
        int pivot_Idx = 0;
        while(l <= r){

            pivot_Idx = partition(l , r , unique , freq);

            if(pivot_Idx == k-1){
                break;
            }

            if(pivot_Idx > k-1){
                r = pivot_Idx - 1;
            }

            if(pivot_Idx < k-1){
                l = pivot_Idx + 1;
            }
        }


        for(int i = 0 ; i <= pivot_Idx ; i++){
            ans.push_back(unique[i]);
        }

        return ans;
    }
};