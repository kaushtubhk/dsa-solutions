class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph , vector<int>& color){
        for(int next : graph[node]){
            if(color[next] == 0){
                color[next] = 3 - color[node];
                if(!dfs(next,graph,color)){
                return false;
                }

            }else if(color[next] == color[node]){
                return false ;
            }
        }
        return true ;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;

        vector<int> color(n,0) ;
        for(int i = 0 ; i < n ; i++){
            if(color[i] == 0){
                color[i] = 1 ;
            }
            if(!dfs(i,graph,color)){
                return false;
            }
        }
        return true ;
        
    }
};