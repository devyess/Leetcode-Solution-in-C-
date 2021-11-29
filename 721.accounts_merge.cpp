class Solution {
private:
    unordered_map<string, string> root; //we're connecting all emails to 1 parent email called root.
    unordered_map<string, string> owner; //Email address belongs to which owner 
    unordered_map<string, set<string>> m; //string -> owner //set<string> -> the owner's email ids list
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        
        for(auto account: accounts){
            for(int i= 1; i< account.size(); i++){
                root[account[i]]= account[i]; //Make each node it's parent
                owner[account[i]]= account[0]; //Owner of each email is the account holder
            }
        }
        
        for(auto account: accounts){
            string p= find(account[1]); //find the parent of a node
            for(int i= 2; i< account.size(); i++){
                root[find(account[i])]= p; //In every account, make the first email, the root of other email nodes.
            }
        }
        
        for(auto account: accounts){
            for(int i= 1; i< account.size(); i++){
                m[find(account[i])].insert(account[i]); //Every email node that has a common parent is inserted at their parent
            }
        }
        for (auto a : m) {
            vector<string> v(a.second.begin(), a.second.end()); //the unique list of emails of an owner person, in sorted order because they belonged to a "set"
            v.insert(v.begin(), owner[a.first]); //Add the owner's name to the list at the beginning
            ans.push_back(v); //Add the list to the result vector
        }
        return ans;
        
    }
    
    string find(string s){
        return root[s]== s? s: find(root[s]); //To find the parent of a node
    } 
};