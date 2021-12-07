class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
      int n=indices.size();
      string p=s;
      for(int i=0;i<n;i++){
      p[indices[i]]=s[i];
      }
      return p;
    }
};
