class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            ans[i]=sum+nums[i];
            sum=ans[i];
        }
        return ans;
    }
};