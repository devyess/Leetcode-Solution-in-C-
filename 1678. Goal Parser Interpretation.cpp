#include<cstring>
class Solution {
public:
    string interpret(string command) {
      int n=command.length();
      string answer="";
      for(int i=0;i<n;i++){
        if(command[i]=='G')
          answer=answer+command[i];
        else if(command[i]=='(' && command[i+1]==')')
          answer=answer+'o';
        else if(command[i]=='('|| command[i]==')')
          answer=answer;
        else
          answer=answer+command[i];
      }
      return answer;
    }
};
