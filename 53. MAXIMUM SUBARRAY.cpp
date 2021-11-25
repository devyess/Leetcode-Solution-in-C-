class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), maxSum = 0, ans = INT_MIN;
        for( int i = 0 ; i < n ; i++ ){
            maxSum += nums[i];
            if( maxSum > ans ) ans = maxSum;
            
            if( maxSum < 0 ) maxSum = 0;
        }
        return ans;
    }
};