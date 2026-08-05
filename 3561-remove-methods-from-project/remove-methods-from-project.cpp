class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> visited(n, false);

        
        dfs(k, adj, visited);

        
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!visited[u] && visited[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        
        vector<int> remaining;

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                remaining.push_back(i);
        }

        return remaining;
    }

    void dfs(int source, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[source] = true;

        for (int neigh : adj[source]) {
            if (!visited[neigh]) {
                dfs(neigh, adj, visited);
            }
        }
    }
};