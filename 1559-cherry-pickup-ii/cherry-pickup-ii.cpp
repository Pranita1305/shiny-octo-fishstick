class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1e9)));

        dp[0][0][n-1]=grid[0][0]+grid[0][n-1];


        for(int i=1;i<m;i++){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int maxx=-1e8;
                    for(int di=-1;di<=1;di++){
                        for(int dj=-1;dj<=1;dj++){
                            int value=0;
                            if(j1==j2){
                                value+=grid[i][j1];
                            }
                            else{
                                value+=grid[i][j1] + grid[i][j2];
                            }
                            if(j1+di>=0 && j1+di<n && j2+dj>=0 && j2+dj<n){
                                value+=dp[i-1][j1+di][j2+dj];
                            }
                            else{
                                continue;
                            }
                            
                            maxx=max(maxx,value);
                        }
                    }
                    dp[i][j1][j2]=maxx;
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dp[m-1][i][j]);
            }
            
        }
        return ans;
    }
};