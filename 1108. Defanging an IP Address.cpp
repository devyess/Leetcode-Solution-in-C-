class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(int i = 0; i < address.length(); i++){
            if(address[i] != '.') ans.push_back(address[i]);
            if(address[i+1] == '.'){
                ans.push_back('[');
                ans.push_back('.');
                ans.push_back(']');                            
            }
        }
        return ans;
    }
};
