class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int m=matrix.size();
      int n=matrix[0].size();
      vector<int> num(m*n,0);
      int i=0;
      while(i<m*n){
        for(int j=0;j<m;j++){
          for(int k=0;k<n;k++){
            num[i]=matrix[j][k];
            i++;
          }
        }
      }
      sort(num.begin(),num.end());
      return num[k-1];
    }
};