class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto e : prerequisites){
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> inDegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }


        queue<int> q;
        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }


        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(topo.size() == V) return topo;
        else return {};
    }
};