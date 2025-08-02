class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
            as we need to do it in O(n) , and we require the left boundary(i.e index + 1 of the histrogram smaller than the current histogram) and the right boundary index for
        */
        int n = heights.size();

        vector<int> leftBoundary(n) , rightBoundary(n);

        stack<int> stL , stR;   // push index , as we need (index + 1) for left boundary and (index - 1) for right boundary

        for(int i = 0 ; i < n ; i++){
            while(!stL.empty() && (heights[stL.top()] >= heights[i])){
                stL.pop();
            }

            if(stL.empty()){
                leftBoundary[i] = 0;
            }else{
                leftBoundary[i] = stL.top() + 1;
            }

            stL.push(i);
        }

        for(int i = n-1 ; i >= 0 ; i--){
            while(!stR.empty() && (heights[stR.top()] >= heights[i])){
                stR.pop();
            }

            if(stR.empty()){
                rightBoundary[i] = n-1;
            }else{
                rightBoundary[i] = stR.top() - 1;
            }

            stR.push(i);
        }


        int maxi = 0;

        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi , (rightBoundary[i] - leftBoundary[i] + 1)*heights[i]);
        }

        return maxi;
    }
};