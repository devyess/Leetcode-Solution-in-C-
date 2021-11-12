class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
     vector<vector<int>> ans;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)
            {
                if(A[i][j]==0)
                    A[i][j]++;
                else A[i][j]--;
            }
        }
        for(int i=0;i<A.size();i++)
        {int p=A[0].size()-1;vector<int> aux;
            for(int j=0;j<A[0].size();j++)
            {
                aux.push_back(A[i][p]);
                p--;
            }
         ans.push_back(aux);
        }
        return ans;
    }
};