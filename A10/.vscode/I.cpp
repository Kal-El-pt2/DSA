#include <iostream>
#include <vector>

using namespace std;

// Define directions for moving (up, down, left, right)
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<int>>& grid, int x, int y) {
    int m = grid.size();
    int n = grid[0].size();

    // Mark the current cell as visited
    grid[x][y] = 0;

    // Explore neighbors
    for (const auto& dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        // Check if the neighbor is within the grid and is land
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
            dfs(grid, nx, ny);
        }
    }
}

int countIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int islandCount = 0;

    // Traverse the grid
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // If current cell is land
            if (grid[i][j] == 1) {
                // Increment island count and perform DFS to mark all connected land cells
                ++islandCount;
                dfs(grid, i, j);
            }
        }
    }

    return islandCount;
}

int main() {
    int m, n;
    cin >> m >> n;

    // Read the grid
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // Count the number of islands
    int islands = countIslands(grid);
    cout << islands << endl;

    return 0;
}
