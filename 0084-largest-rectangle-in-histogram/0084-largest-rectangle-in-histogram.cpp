class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Approach 2 --> Doing it in one pass , as i don't need to traverse twice to get the leftBoundary and rightBoundary 

        int maxA = 0 , n = heights.size();

        stack<int> st;
 
        for(int i = 0 ; i <= n ; i++){
            while(!st.empty() && ((i == n) || (heights[st.top()] > heights[i]))){
                int rightBoundary = i;
                int height = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()) width = i;
                else width = rightBoundary - st.top() - 1;

                maxA = max(maxA , width * height);
            }
            st.push(i);
        }

        return maxA;
    }
};