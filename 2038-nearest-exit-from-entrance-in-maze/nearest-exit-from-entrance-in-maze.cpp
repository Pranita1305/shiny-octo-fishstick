class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int m = maze.size();
        int n = maze[0].size();

        vector<pair<int,int>> dirs = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        queue<pair<int,int>> q;
        set<pair<int,int>> visited;

        q.push({entrance[0], entrance[1]});
        visited.insert({entrance[0], entrance[1]});

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();
            steps++;

            while (sz--) {

                auto [r,c] = q.front();
                q.pop();

                for (auto [dr,dc] : dirs) {

                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        maze[nr][nc] == '.' &&
                        visited.find({nr,nc}) == visited.end()) {

                       
                        if (nr == 0 || nr == m-1 ||
                            nc == 0 || nc == n-1) {
                            return steps;
                        }

                        visited.insert({nr,nc});
                        q.push({nr,nc});
                    }
                }
            }
        }

        return -1;
    }
};