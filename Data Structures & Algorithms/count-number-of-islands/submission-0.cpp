class Solution {
public:
    // int numIslands(vector<vector<char>>& grid) {
    //     vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

    //     int res = 0;
    //     for(int i = 0; i < grid.size(); i++){
    //         for(int j = 0; j < grid[i].size(); j++){
    //             char node = grid[i][j];
    //             // If coordinates is not visited, and is island.
    //             if(node == '1' && vis[i][j] == false){
    //                 res++;
    //                 dfs(grid, vis, i, j);
    //             }
    //         }
    //     }

    //     return res;
    // }

    // void dfs(vector<vector<char>>& grid, vector<vector<bool>> &vis, int i, int j ){
    //     // marked as visited
    //     vis[i][j] = true;

    //     // check it's under bound, not visited, and 1's
    //     if((j+1) < grid[0].size() && !vis[i][j+1] && grid[i][j+1] == '1' ){
    //         dfs(grid, vis, i, j+1);
    //     }

    //     if((j - 1) >=0 && !vis[i][j-1] && grid[i][j-1] == '1' ){
    //         dfs(grid, vis, i, j-1);
    //     }

    //     if((i+1) < grid.size() && !vis[i+1][j] && grid[i+1][j] == '1' ){
    //         dfs(grid, vis, i + 1, j);
    //     }

    //     if((i-1) >= 0 && !vis[i-1][j] && grid[i-1][j] == '1' ){
    //         dfs(grid, vis, i-1, j);
    //     }

    // }
    int numIslands(vector<vector<char>>& grid) {

        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                char node = grid[i][j];
                // If coordinates is not visited, and is island.
                if(node == '1'){
                    res++;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j ){
        // marked as visited
        grid[i][j] = '0';

        // check it's under bound, not visited, and 1's
        if((j+1) < grid[0].size() && grid[i][j+1] == '1' ){
            dfs(grid, i, j+1);
        }

        if((j - 1) >=0 && grid[i][j-1] == '1' ){
            dfs(grid, i, j-1);
        }

        if((i+1) < grid.size()  && grid[i+1][j] == '1' ){
            dfs(grid, i + 1, j);
        }

        if((i-1) >= 0 && grid[i-1][j] == '1' ){
            dfs(grid, i-1, j);
        }

    }
};
