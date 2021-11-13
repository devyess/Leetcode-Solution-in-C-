class Solution {
public:
    bool isHappy(int n) {
        if (n == 1 || n == 7) return true;
        
        string number = to_string(n);
        int sum = 0;
        
        while(number.size() != 1) {
            sum = 0;
            for (int i = 0; i < number.size(); i++) {
                stringstream ss;  
                ss << number[i];  
                int tmp = 0;
                ss >> tmp; 
                sum += tmp * tmp;
            }
            number = to_string(sum);
        }
        
        if (sum == 1 || sum == 7) return true;
        return false;
    }
};