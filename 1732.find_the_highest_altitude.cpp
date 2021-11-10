class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      int n=gain.size();
      vector<int> range(n+1,0);
      range[0]=0;
      range[1]=gain[0];
      for(int i=2;i<n+1;i++){
        range[i]=gain[i-1]+range[i-1];
      }
      int max =0;
      for(int j=0;j<n+1;j++){
        if(range[j]>max){
          max=range[j];
        }
      }
      return max;
    }
};