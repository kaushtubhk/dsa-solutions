class Solution{
public:

    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size();
        int n = heightMap[0].size();

        // Edge case
        if(m < 3 || n < 3) return 0;

        // Min heap: {height, row, col}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > minHeap;

        // Visited array
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Step 1: Saari border cells heap mein daalo
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(i == 0 || i == m-1 || j == 0 || j == n-1) {

                    minHeap.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }

        // 4 directions
        int dirs[4][2] = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        int totalWater = 0;

        // Step 2: Process karo
        while(!minHeap.empty()) {

            // Sabse choti wall nikalo
            auto [h, r, c] = minHeap.top();
            minHeap.pop();

            // Uske 4 neighbours check karo
            for(auto& d : dirs) { 
                // Matlab: dirs ki har row ek baar lo

                int nr = r + d[0]; 
                // nr means new row
                // r = current row
                // d[0] = row direction(kitna change)

                int nc = c + d[1]; 
                // ex. d = {0,1}
                // d[0] = 0
                // d[1] = 1
                // nc = c + d[1]
                // mtlb column ek right side gya

                // Valid aur unvisited?
                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if(visited[nr][nc])
                    continue;

                visited[nr][nc] = true;

                // Paani trap hoga?
                if(heightMap[nr][nc] < h) {

                    // agr neighbour chota hai
                    // paani = h - neighbour ki height
                    totalWater += h - heightMap[nr][nc];

                    // Effective height update karo
                    heightMap[nr][nc] = h;

                    // heightMap[nr][nc]
                    // neighbour ki height
                }

                // Heap mein daalo
                minHeap.push({heightMap[nr][nc], nr, nc});
            }
        }

        return totalWater;
    }
};

// Time: O(m × n × log(m × n))
// Har cell ek baar heap mein
// Heap operation = log(size)

// Space: O(m × n)
// visited array + heap