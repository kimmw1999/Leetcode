class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> curr;
        NQueens(res, curr, 0, n);
        return res;
    }
private:
    void put_queens(vector<vector<string>> &res, vector<int> &curr, int n) {
        vector<string> puzzle;
        for(int i = 0; i < curr.size(); i++) {
            string row = string(n, '.');
            row[curr[i]] = 'Q';
            puzzle.push_back(row);
            cout << row << " ";
        }
        cout << endl;
        res.push_back(puzzle);
    }

    bool valid(vector<int> &curr, int i, int row) {
        for(int r = 0; r < curr.size(); r++) {
            int c = curr[r];
            if((abs(row - r) == abs(i - c))|| (i == c)) {
                return false;
            }
        }
        return true;
    }

    void NQueens(vector<vector<string>> &res, vector<int> &curr, int r, int n) {
        if(r == n) {
            put_queens(res, curr, n);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(valid(curr, i, r)) {
                curr.push_back(i);
                NQueens(res, curr, r+1, n);
                curr.pop_back();
            }
        }
    }
};