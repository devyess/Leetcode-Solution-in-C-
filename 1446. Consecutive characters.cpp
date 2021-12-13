class Solution {
public:
    int maxPower(string s) {
        int max=0;
        for(int i=0;i<s.size();i++){
            int count=1;
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j]){
                    count++;
                }
                else
                    break;
            }
            if(count>max)
                max=count;
        }
        return max;
    }
};
