//Date: 04/27/2027
//O(M) space 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> colsWith0;
        for(int r = 0; r < matrix.size(); r++) {
            bool found0 = false;
            for(int c = 0; c < matrix[0].size(); c++) {
                if(matrix[r][c] == 0) {
                    colsWith0.insert(c);
                    found0 = true;
                }
            }
            if(found0) {
                for(int c = 0; c < matrix[0].size(); c++) {
                    matrix[r][c] = 0;
                }
                // printMatrix(r, matrix);
            }
        }
        for(int c : colsWith0) {
            for(int r = 0; r < matrix.size(); r++) {
                matrix[r][c] = 0;
            }
        }
    }
private:
    void printMatrix(int r, vector<vector<int>> matrix) {
        cout<< "row: " << r << endl;
        for(int i = 0 ; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                cout << matrix[i][j] << " " ;
            }
            cout << endl;
        }
        cout << "---------------------" << endl;
    }
};


//Date: 04/27/2024
//Space: O(1)
class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool start0 = matrix[0][0] == 0;
        bool row0 = start0;
        bool col0 = start0;
        // cout << start0 << " " << row0 << " " << col0 << " " << endl;
        // printMatrix("start", matrix);
        //check first row & first column 0's
        for(int r = 1; r < matrix.size(); r++) {
            if(matrix[r][0] == 0) {
                row0 = true;
                matrix[0][0] = 0;
                break;
            }
        }

        for(int c = 1; c < matrix[0].size(); c++) {
            if(matrix[0][c] == 0) {
                col0 = true;
                matrix[0][0] = 0;
                break;
            }
        }
        // cout << start0 << " " << row0 << " " << col0 << " " << endl;
        // printMatrix("1st row & 1st column check\n", matrix);

        //find 0's and mark to 1st row & column
        for(int r = 1; r < matrix.size(); r++) {
            for(int c = 1; c < matrix[0].size(); c++) {
                if(matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        // printMatrix("mark 0's\n", matrix);

        //color by row
        for(int r = 1; r < matrix.size(); r++) {
            if(matrix[r][0] == 0) {
                for(int c = 0; c < matrix[0].size(); c++) {
                    matrix[r][c] = 0;
                }
            }
        }
        // printMatrix("color by row\n", matrix);

        //color by column
        for(int c = 1; c < matrix[0].size(); c++) {
            if(matrix[0][c] == 0) {
                for(int r = 0; r < matrix.size(); r++) {
                    matrix[r][c] = 0;
                }
            }
        }
        // printMatrix("color by column\n", matrix);

        //color first row & column
        if(start0 || row0) {
            for(int r = 0; r < matrix.size(); r++) {
                matrix[r][0] = 0;
            }
        }
        if(start0 || col0) {
            for(int c = 0; c < matrix[0].size(); c++) {
                matrix[0][c] = 0;
            }
        }
        // printMatrix("final result\n", matrix);
    }
private:
    void printMatrix(string str, vector<vector<int>> matrix) {
        cout<< str  << endl;
        for(int i = 0 ; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                cout << matrix[i][j] << " " ;
            }
            cout << endl;
        }
        cout << "---------------------" << endl;
    }
};