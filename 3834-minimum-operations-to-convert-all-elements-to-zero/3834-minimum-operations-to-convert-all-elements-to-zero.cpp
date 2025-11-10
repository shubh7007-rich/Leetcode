class Solution {
public:
    /*
        [5,6,7,4,6,7,6,7,5,5]

    */
    int minOperations(vector<int>& nums) {
        stack<int> st;

        int n = nums.size() , cnt = 0;

        // unordered_set<int> sett;

        for(int i = 0 ; i < n ; i++){
            if(st.empty()){
                st.push(nums[i]);
                // sett.insert(nums[i]);
                if(nums[i] != 0) cnt++;
            }else{
                if(st.top() > nums[i]){
                    while(!st.empty() && st.top() > nums[i]){
                        // sett.erase(st.top());
                        st.pop();
                    }
                    if(st.empty() || (st.top() < nums[i])) {
                        
                        st.push(nums[i]);
                        if(nums[i] != 0) cnt++;
                        // sett.insert(nums[i]);
                    }
                }else{
                    if(st.empty() || (st.top() < nums[i])) {
                        
                        st.push(nums[i]);
                        if(nums[i] != 0) cnt++;
                        // sett.insert(nums[i]);
                    }
                }
                
            }
        }

        return cnt;
    }
};

struct FastIOS {
    FastIOS() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;