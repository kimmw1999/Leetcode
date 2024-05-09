class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(), 0);
        int maxA = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                heights[j] = matrix[i][j] == '1' ? heights[j]+1 : 0;
            }

            maxA = max(maxA, maxAreaRectangle(heights));
        }
        return maxA;
    }

    int maxAreaRectangle(vector<int> &heights) {
        stack<int> st;
        st.push(-1);
        int maxA = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(st.top() != -1 && heights[st.top()] > heights[i]) {
                int currH = heights[st.top()];
                st.pop();
                int currW = i - (st.top() + 1);
                maxA = max(maxA, currH * currW);
            }
            st.push(i);
        }

        while(st.top() != -1) {
            int currH = heights[st.top()];
            st.pop();
            int currW = heights.size() - (st.top() + 1);
            maxA = max(maxA, currH * currW);
        }
        return maxA;
    }
};