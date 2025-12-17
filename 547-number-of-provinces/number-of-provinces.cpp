class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (int j = 0; j < adj.size(); j++) {
            if (adj[node][j] == 1 && !vis[j]) {
                dfs(j, adj, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};
