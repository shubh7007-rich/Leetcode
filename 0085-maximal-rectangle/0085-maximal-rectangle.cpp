class Solution {
public:
    int func(vector<int>& heights , int m){
        vector<int> ls(m) , rs(m);

        stack<int> st;

        for(int i = 0 ; i < m ; i++){
            while(!st.empty() && (heights[st.top()] >= heights[i])){
                st.pop();
            }

            if(st.empty()) ls[i] = 0;
            else ls[i] = st.top() + 1;
            
            st.push(i);
        }

        stack<int> st1;

        for(int i = m-1 ; i >= 0 ; i--){
            while(!st1.empty() && (heights[st1.top()] >= heights[i])){
                st1.pop();
            }

            if(st1.empty()) rs[i] = m-1;
            else rs[i] = st1.top() - 1;

            st1.push(i);
        }

        int maxA = 0;

        for(int i = 0; i < m ; i++){
            int heigh = heights[i];

            int width = rs[i] - ls[i] + 1;

            maxA = max(maxA , heigh * width);
        }

        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size() , m = mat[0].size();

        int maxA = 0;

        vector<int> heights(m , 0);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == '1'){
                    heights[j]++;
                }else{
                    heights[j] = 0;
                }
            }

            maxA = max(maxA , func(heights , m));

        }
        return maxA;
    }

};