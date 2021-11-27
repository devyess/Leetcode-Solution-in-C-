class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1,count=0,zero=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) 
                count++;                                
            if(count<=1 && nums[i]!=0) 
                zero*=nums[i];                        
            prod*=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)             
            {
                if(count==1)             
                    nums[i]=zero;         
                else
                    nums[i]=prod;         
            }
            else
                nums[i]=prod/nums[i];           
        }
        return nums;
    }
};