class Solution {
private:
    bool bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>, pair<int, int>>> q;
        q.push({{i, j}, {-1, -1}});
        vis[i][j] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int prow = q.front().second.first;
            int pcol = q.front().second.second;
            q.pop();
            for(int i=0; i<4; i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m &&
                    vis[newrow][newcol] &&
                    grid[newrow][newcol] == grid[row][col] &&
                    !(newrow == prow && newcol == pcol)){
                        return true;
                }
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && 
                !vis[newrow][newcol] && grid[newrow][newcol] == grid[row][col]){
                    q.push({{newrow, newcol}, {row, col}});
                    vis[newrow][newcol] = 1;
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0){
                    if(bfs(i, j, grid, vis)) return true;
                }
            }
        }
        return false;
    }
};