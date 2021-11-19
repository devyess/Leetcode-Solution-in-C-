class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
      int n=mat[0].size();
      int sum=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(i==j)
            sum=sum+mat[i][j];
        }
      }
      for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
          if(i+j==n-1)
            sum=sum+mat[i][j];
        }
      }
      if(n%2!=0){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(i==n/2 && j==n/2)
            sum=sum-mat[i][j];
        }
      }
      }
      return sum;
    }
};