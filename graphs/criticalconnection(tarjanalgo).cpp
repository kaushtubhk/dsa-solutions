class Solution {
public:
    vector<vector<int>> ans ;
    vector<vector<int>> adj ;

    vector<int> tin , low ;

    int timer = 0 ;
    void dfs(int u , int parent){
        tin[u] = low[u] = timer++ ;
        for(int v : adj[u]){
            if(v == parent){
                continue;
            }
            if(tin[v] != -1){
                low[u] = min(low[u] , tin[v]);
            }else{
                dfs(v,u);
                low[u] = min(low[u] , low[v]);

                if(low[v] > tin[u]){
                    ans.push_back({u,v});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n) ;
        for(auto edge : connections){
            int u = edge[0] ;
            int v = edge[1] ;
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        tin.assign(n, -1) ;
        low.assign(n , -1) ;
        dfs(0,-1);

        return ans ;
    }
};