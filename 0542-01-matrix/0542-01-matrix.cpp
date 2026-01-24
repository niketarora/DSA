class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int> , int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                    q.push({{i,j}, 0});
                }
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int newrow = r + drow[i];
                int newcol = c + dcol[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && 
                grid[newrow][newcol] == 1 && vis[newrow][newcol] == 0){
                    q.push({{newrow,newcol}, dis + 1});
                    ans[newrow][newcol] = dis + 1;
                    vis[newrow][newcol] = 1;
                }
            }
        }
        return ans;
    }
};