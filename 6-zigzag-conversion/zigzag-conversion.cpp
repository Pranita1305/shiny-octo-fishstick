class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        
        // Edge case: If there is only one row or the string is too short to zigzag
        if (numRows == 1 || n <= numRows) {
            return s;
        }

        vector<string> pattern(numRows,"");

        int dir=-1;
        int j=0;

        for(int i=0;i<n;i++){
            if(j==numRows-1 || j==0){
                if(dir==1) dir=-1;
                else dir=1;
            }
            pattern[j]+=s[i];
            if(dir==1) j++;
            else j--;

        }

        // vector<vector<char>> pattern(numRows);
        // int i = 0;
        // int j = 0;
        // bool flag = true; // true indicates moving down, false indicates moving up

        // while (i < n) {
        //     if (flag) {
        //         // Move downward from row 0 to numRows - 1
        //         while (i < n && j < numRows) {
        //             pattern[j].push_back(s[i]);
        //             i++;
        //             j++;
        //         }
        //         // Prepare for the upward diagonal move
        //         j = numRows - 2;
        //         flag = false;
        //     } else {
        //         // Move upward from row numRows - 2 down to row 1
        //         while (i < n && j > 0) {
        //             pattern[j].push_back(s[i]);
        //             i++;
        //             j--;
        //         }
        //         // Prepare for the downward move starting at row 0
        //         j = 0;
        //         flag = true;
        //     }
        // }

        // Reconstruct the final string from the pattern rows
        string res = "";
        for(string s:pattern){
            res+=s;
        }

        return res;
    }
};