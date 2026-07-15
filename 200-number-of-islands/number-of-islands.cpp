class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int count=0;

        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]=='1'){
                    count++;
                    dfs(grid,r,c);
                }
            }
        }

        

        return count;
        
    }
private:
    // void bfs(vector<vector<char>>& grid, int r, int c,unordered_set<string>& vis,vector<pair<int,int>>& dir, int n, int m){
    //     queue<pair<int,int>> q;
    //     q.push({r,c});

    //     vis.insert({to_string(r)+","+to_string(c)});

    //     while(!q.empty()){
    //         auto [row,col]=q.front();
    //         q.pop();

    //         for(auto [dr,dc]:dir){
    //             int nr=r+dr;
    //             int nc=c+dc;

    //             if(nr>=0 && nr<n && nc>=0 && nc<m){
    //                 q.push({nr,nc});
    //                 vis.insert(to_string(nr) + "," + to_string(nc));
    //             }
    //         }
    //     }
    // }

    void dfs(vector<vector<char>>& grid, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '0'; // mark as visited
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
    
};