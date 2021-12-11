class Solution {
public:
    #define mod 1000000007   
    
    int nthMagicalNumber(int n, int a, int b) {
        int lcm = (a*b)/__gcd(a,b);
        long long int left=min(a,b) , right=n*1LL*min(a,b);
        long long int ans = 0;
        while(left<=right){
            
            long long int mid = (left + (right-left)/2);
            
            long long int position_check = mid/b + mid/a - mid/lcm ;
        
            if(position_check < n) left = mid +1 ;
            
            else {
             ans=mid%mod;
             right=mid-1;
         }
        }
        return ans;
    }  
};
