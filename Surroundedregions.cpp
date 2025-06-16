class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();

        // Helper lambda function to perform DFS
        auto dfs = [&](int r, int c, auto& dfs_ref) {
            if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') return;
            board[r][c] = '#'; // Mark the cell as visited and part of a border-connected region
            dfs_ref(r - 1, c, dfs_ref); // Up
            dfs_ref(r + 1, c, dfs_ref); // Down
            dfs_ref(r, c - 1, dfs_ref); // Left
            dfs_ref(r, c + 1, dfs_ref); // Right
        };

        // Step 1: Mark all 'O's on the borders and their connected 'O's
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, dfs);
            if (board[i][cols - 1] == 'O') dfs(i, cols - 1, dfs);
        }
        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O') dfs(0, j, dfs);
            if (board[rows - 1][j] == 'O') dfs(rows - 1, j, dfs);
        }

        // Step 2: Flip all remaining 'O's to 'X', and convert '#' back to 'O'
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X'; // Surrounded region
                if (board[i][j] == '#') board[i][j] = 'O'; // Non-surrounded region
            }
        }
    }
};
