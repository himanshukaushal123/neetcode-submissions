class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int r, int c) {

        visited[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Out of bounds
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            // Already visited
            if (visited[nr][nc])
                continue;

            // Reverse flow:
            // We can move from current cell to a neighbor
            // only if neighbor's height >= current height.
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(heights, visited, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific Ocean:
        // Top row + Left column
        for (int c = 0; c < n; c++) {
            dfs(heights, pacific, 0, c);
        }

        for (int r = 0; r < m; r++) {
            dfs(heights, pacific, r, 0);
        }

        // Atlantic Ocean:
        // Bottom row + Right column
        for (int c = 0; c < n; c++) {
            dfs(heights, atlantic, m - 1, c);
        }

        for (int r = 0; r < m; r++) {
            dfs(heights, atlantic, r, n - 1);
        }

        vector<vector<int>> ans;

        // Cell can reach both oceans
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};
