class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int res = 0;

        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int init = 0;
                    int sum = dfs(grid, i, j, init);
                    res = max(res, sum);
                }
            }
        }

        return res;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int &total){
        grid[i][j] = 0;
        total++;

        // check it's under bound, not visited, and 1's
        if((j+1) < grid[0].size() && grid[i][j+1] == 1 ){
            dfs(grid, i, j+1, total);
        }

        if((j - 1) >=0 && grid[i][j-1] == 1 ){
            dfs(grid, i, j-1, total);
        }

        if((i+1) < grid.size()  && grid[i+1][j] == 1 ){
            dfs(grid, i + 1, j, total);
        }

        if((i-1) >= 0 && grid[i-1][j] == 1 ){
            dfs(grid, i-1, j, total);
        }

        return total;
    }
};
