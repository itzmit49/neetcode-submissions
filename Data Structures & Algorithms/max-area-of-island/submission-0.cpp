class Solution {
public:
    int dfs(int i,int j,int m,int n,vector<vector<int>>& grid){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0)return 0;
      
            grid[i][j]=0;
            
    
    int down=dfs(i+1, j,m,n, grid);
   int up= dfs(i-1, j,m,n, grid);
   int right= dfs(i, j+1,m,n, grid);
   int left= dfs(i, j-1,m,n, grid);

   return 1+ down+up+right+left;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int m=grid.size();
        int  n=grid[0].size();
        int area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int a=dfs(i,j,m,n,grid);
                    area=max(a,area);
                    
                }
            }
        }
        return area;
    }
};