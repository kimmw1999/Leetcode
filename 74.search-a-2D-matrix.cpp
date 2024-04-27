/*
Date: 04/27/2024
Time Complexity: O(log(N * M))
Space Complexity: O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //binary search 
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int r = n * m - 1;
        // printMatrix(matrix);
        while(l <= r) {
            int mid = (l + r) / 2;
            int i = mid / m;
            int j = mid % m;
            // printStatus(l, r, mid);
            if(matrix[i][j] == target) {
                return true;
            }
            else if(matrix[i][j] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
            
        }
        return false;
    }
private: 
    void printMatrix(vector<vector<int>> matrix) {
        for(int i = 0 ; i< matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                cout << matrix[i][j] << "   ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void printStatus(int i , int j, int mid) {
        cout << "l: " << i << "  r: " << j << "  mid: " << mid << endl;
    }
};