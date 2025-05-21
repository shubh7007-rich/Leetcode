class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        stack<pair<int , int>> st;
        int n = matrix.size() , m = matrix[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;  j < m ; j++){
                if(matrix[i][j] == 0){
                    st.push({i , j});
                }
            }
        }

        while(!st.empty()){
            auto p = st.top();
            st.pop();

            int r = p.first , c = p.second;

            for(int i = r-1 ; i >= 0 ; i--){
                matrix[i][c] = 0;
            }

            for(int i = c-1 ; i >= 0 ; i--){
                matrix[r][i] = 0;
            }

            for(int i = r+1 ; i < n ; i++){
                matrix[i][c] = 0;
            }

            for(int i = c+1 ; i < m ; i++){
                matrix[r][i] = 0;
            }
        }

        // return matrix;
    }
};