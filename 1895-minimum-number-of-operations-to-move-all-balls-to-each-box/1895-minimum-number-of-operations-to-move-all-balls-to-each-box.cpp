class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n , 0);

        vector<int> psum(n , 0) , ssum(n , 0);
        int cnt = 0;
        if(boxes[0] == '1') cnt++;
        for(int i = 1 ; i < n; i++){
            psum[i] = psum[i-1] + cnt;
            if(boxes[i] == '1') cnt++;
        }
        cnt = 0;
        if(boxes[n-1] == '1') cnt++;
        for(int i = n-2 ; i >= 0; i--){
            ssum[i] = ssum[i+1] + cnt;
            if(boxes[i] == '1') cnt++;
        }

        for(int i = 0 ; i < n ; i++){
            ans[i] = psum[i] + ssum[i];
        }

        return ans;
    }
};