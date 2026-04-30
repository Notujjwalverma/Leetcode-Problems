class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int NEG = -1e9;
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, NEG))
        );
        dp[0][0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int gain = grid[i][j];
                int cost = (grid[i][j] == 0 ? 0 : 1);
                for (int c = cost; c <= k; c++) {
                    int best = NEG;

                    if (i > 0 && dp[i - 1][j][c - cost] != NEG) {
                        best = max(best, dp[i - 1][j][c - cost] + gain);
                    }
                    if (j > 0 && dp[i][j - 1][c - cost] != NEG) {
                        best = max(best, dp[i][j - 1][c - cost] + gain);
                    }
                    dp[i][j][c] = best;
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }

        return ans < 0 ? -1 : ans;
    }
};