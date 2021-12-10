class Solution {
public:
    int balancedStringSplit(string s) {
        int count_r = 0 , count_l = 0 , answer = 0;
        
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'R') count_r++;
            if(s[i] == 'L') count_l++;
            
            if(count_r == count_l && count_r != 0) answer++;
        }
        return answer;
    } 
};