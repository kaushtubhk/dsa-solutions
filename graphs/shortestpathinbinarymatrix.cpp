class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1 ;
        }
        if(n == 1){
            return 1 ;
        }
        int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1}, {0,1},{1,-1},{1,0},{1,1}};

        queue<pair<int , int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int path = 1 ;
        while(!q.empty()){
            int size = q.size();
            path++ ;

            for(int i = 0 ; i < size ; i++){
                auto[r , c] = q.front();
                q.pop() ;

                for(auto& d : dirs){
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc<n && grid[nr][nc] == 0){
                        if(nr == n-1 && nc == n-1){
                            return path ;
                        }
                        grid[nr][nc] = 1 ;
                        q.push({nr , nc}) ;

                    }
                    

                }
            }
        }
        return -1 ;
        
    }
};