class CombinationIterator {
    string s;
    string p;
    int id;
public:
    
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        sort(s.begin(), s.end());
        for(int i = 0;i < combinationLength;i++){
            p += '1';
        }
        
        while(p.length() < s.length()){
            p += '0';
        }
        id = 0;
    }
    
    string next() {
        
        if(id > 0){
            prev_permutation(p.begin(), p.end());
        }
        
        string ans = "";
        for(int i = 0 ;i < p.length();i++){
            if(p[i] == '1'){
                ans += s[i];
            }
        }
        id++;
        return ans;
    }
    
    bool hasNext() {
        return not is_sorted(p.begin(), p.end());
    }
};