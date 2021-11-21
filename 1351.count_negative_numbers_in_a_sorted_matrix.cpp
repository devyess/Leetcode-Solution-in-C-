class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      int n=grid.size();
      int k=grid[0].size();
      int count=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
          if(grid[i][j]<0)
            count++;
        }
      }
      return count;
    }
};