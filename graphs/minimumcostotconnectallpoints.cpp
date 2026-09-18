class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size() ;
        vector<int> minDist(n , INT_MAX) ;
        vector<bool> visited(n , false) ;

        minDist[0] = 0 ;
        int ans = 0 ;
        for(int count = 0 ; count < n ; count++){
            int u = -1 ;
            for(int i = 0 ; i < n ; i++){
                if(!visited[i] && (u == -1 || minDist[i] < minDist[u])){
                    u = i ;
                }
            }
            visited[u] = true ;
            ans += minDist[u] ;

            for(int v = 0 ; v < n ; v++){
                if(!visited[v]){
                    int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]) ;
                    minDist[v] = min(minDist[v] , cost) ;
                }
            }
        }
        return ans ; 
        
    }
};