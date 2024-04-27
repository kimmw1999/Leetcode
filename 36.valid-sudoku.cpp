class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> boxes(9);
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                char val = board[r][c];
                if (val != '.') {
                    int boxIndex = (r / 3) * 3 + c / 3;
                    
                    // Check if the value is already in the current row, column, or box
                    if (rows[r].find(val) != rows[r].end() || 
                        cols[c].find(val) != cols[c].end() || 
                        boxes[boxIndex].find(val) != boxes[boxIndex].end()) {
                        return false;
                    }

                    // Insert the value into the current row, column, and box
                    rows[r].insert(val);
                    cols[c].insert(val);
                    boxes[boxIndex].insert(val);
                }
            }
        }
        
        return true;
    }
};