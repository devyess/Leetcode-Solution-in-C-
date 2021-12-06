class Solution {
public:
    int specialArray(vector<int>& a) {
        int i,j;
        sort(a.begin(),a.end());
        int lolo=*max_element(a.begin(),a.end());
        for(i=0;i<=lolo;i++)
        {
            int cnt=0;
            for(j=0;j<a.size();j++)
            {
                if(a[j]>=i)
                    cnt++;
                
            }
            if(cnt==i)
            {
                return i;
            }
        }
        return -1;
    }
};