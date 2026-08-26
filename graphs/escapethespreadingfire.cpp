class Solution {
public:

    int m, n;
    int dirs[4][2] = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    vector<vector<int>> fire;

    bool canEscape(vector<vector<int>>& grid, int wait) {

        vector<vector<int>> dist(m, vector<int>(n, -1));

        queue<pair<int,int>> q;

        q.push({0,0});
        dist[0][0] = wait;

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            int time = dist[r][c];

            for(auto &d : dirs) {

                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if(grid[nr][nc] == 2)
                    continue;

                if(dist[nr][nc] != -1)
                    continue;

                int nextTime = time + 1;

                if(nr == m-1 && nc == n-1) {
                    if(fire[nr][nc] >= nextTime)
                        return true;
                }
                else {
                    if(fire[nr][nc] > nextTime) {
                        dist[nr][nc] = nextTime;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return false;
    }


    int maximumMinutes(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        fire.assign(m, vector<int>(n, INT_MAX));

        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    fire[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            for(auto &d : dirs) {

                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if(grid[nr][nc] == 2)
                    continue;

                if(fire[nr][nc] != INT_MAX)
                    continue;

                fire[nr][nc] = fire[r][c] + 1;

                q.push({nr,nc});
            }
        }

        // If we cannot escape even without waiting
        if(!canEscape(grid, 0))
            return -1;

        int low = 0;
        int high = 1e9;
        int ans = 0;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(canEscape(grid, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};