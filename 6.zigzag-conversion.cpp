class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        vector<string> rows(numRows, "");
        int j = 0;
        int dir = -1;
        for(int i = 0; i < s.size(); i++) {
            if(j == numRows-1 || j == 0) {
                dir *= -1;
            }

            rows[j] += s[i];
            j += dir;
        }
        string result;
        for(string row : rows) {
            result += row;
        }
        return result;
        // if(numRows == 1) {
        //     return s;
        // }
        // int m = s.size();
        // string result(m, 'a');
        // int resIdx = 0;
        // for(int i = 0; i < numRows; i++) {
        //     result[resIdx] = s[i];
        //     resIdx++;

        //     int curIdx = i;
        //     while(curIdx < m) {
        //         if( i == 0 || i == numRows - 1) {
        //             curIdx += (numRows - 1) * 2;
        //             if(curIdx >= m) {
        //                 break;
        //             }
        //             result[resIdx] = s[curIdx];
        //             resIdx++;
        //         }
        //         else{
        //             curIdx += (numRows - i - 1) * 2;
        //             if(curIdx >= m) {
        //                 break;
        //             }
        //             result[resIdx] = s[curIdx];
        //             resIdx++;

        //             curIdx += i * 2;
        //             if(curIdx >= m) {
        //                 break;
        //             }
        //             result[resIdx] = s[curIdx];
        //             resIdx++;
        //         }
        //     }
        // }
        // return result;
    }
};