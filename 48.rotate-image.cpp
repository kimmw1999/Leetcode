class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int top = 0;
        int bot = matrix.size() - 1;
        int left = top;
        int right = bot;

        while(top < bot) {
            for(int i = 0; i < bot - top; i++) {
                swap(matrix[top][left + i], matrix[bot-i][left]);
                swap(matrix[bot-i][left], matrix[bot][right-i]);
                swap(matrix[bot][right-i], matrix[top+i][right]);
            }
            top++;
            bot--;
            left = top;
            right = bot;

        }
    }

};