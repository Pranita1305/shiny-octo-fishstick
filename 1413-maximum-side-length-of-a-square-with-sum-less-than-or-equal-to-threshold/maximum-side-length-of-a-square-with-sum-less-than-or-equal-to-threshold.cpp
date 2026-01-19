class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        // Compute prefix sum matrix
        vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int left = 1, right = min(m, n), ans = 0;
        while(left <= right) {
            int k = left + (right - left) / 2;
            bool found = false;
            for(int i = k; i <= m; ++i) {
                for(int j = k; j <= n; ++j) {
                    int total = prefix[i][j] - prefix[i-k][j] - prefix[i][j-k] + prefix[i-k][j-k];
                    if(total <= threshold) {
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            if(found) {
                ans = k;
                left = k + 1;
            } else {
                right = k - 1;
            }
        }
        return ans;
    }
};