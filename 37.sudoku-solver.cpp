class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), grids(9);
        //unfilled numbers for each row, col, grid
        for(int k = 0; k < 9; k++) {
            for(int i = 1; i < 10; i++) {
                rows[k].insert('0' + i);
                cols[k].insert('0' + i);
                grids[k].insert('0' + i);
            }
        }

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] == '.') {
                    continue;
                }
                //grid number
                int g = (r / 3) * 3 + (c / 3);
                char val = board[r][c];
                rows[r].erase(val);
                cols[c].erase(val);
                grids[g].erase(val);
            }
        }

        backtracking(board, rows, cols, grids, 0, 0);
        return;
    }

private:
    bool backtracking(vector<vector<char>> &board, vector<unordered_set<char>> &rows, 
                        vector<unordered_set<char>> &cols, vector<unordered_set<char>> &grids, int r, int c) {
        if (c == 9) {
            r++;
            c = 0;
        }
        if (r == 9) {
            return true;
        }
        if(board[r][c] != '.') {
            return backtracking(board, rows, cols, grids, r, c+1);
        }
        else{
            int g = (r / 3) * 3 + (c / 3);
            for(int i = 1; i < 10; i++) {
                char val = '0' + i;
                if(rows[r].find(val) != rows[r].end() &&
                   cols[c].find(val) != cols[c].end() &&
                   grids[g].find(val) != grids[g].end()) {
                    char temp = board[r][c];
                    board[r][c] = val;

                    rows[r].erase(val);
                    cols[c].erase(val);
                    grids[g].erase(val);
                    if(backtracking(board, rows, cols, grids, r, c+1)) {
                        return true;
                    }
                    rows[r].insert(val);
                    cols[c].insert(val);
                    grids[g].insert(val);
                    board[r][c] = temp;
                }
            }
            return false;
        }
    }
};