class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        for(int i=t.size()-2;i>=0;i--){
            for(int j=0;j<t[i].size();j++){
                int b=t[i+1][j];
                int r=t[i+1][j+1];

                t[i][j]+=min(b,r);
            }
        }

        return t[0][0];
    }
};