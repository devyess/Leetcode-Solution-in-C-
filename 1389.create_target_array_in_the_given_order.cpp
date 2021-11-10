class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
      int n=nums.size();
      vector<int> ans(n,INT_MAX);
      for(int i=0;i<n;i++){
        if(ans[index[i]]==INT_MAX)
          ans[index[i]]=nums[i];
        else
        {
          int temp=ans[index[i]];
          ans[index[i]]=nums[i];
          int newindices=index[i]+1;
          while(newindices<n){
            int temp1=ans[newindices];
            ans[newindices]=temp;
            temp=temp1;
            newindices++;
          }
        }
      }
      return ans;
    }
};