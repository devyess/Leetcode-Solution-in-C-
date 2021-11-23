class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        int j = 0;
        int counter = 0;
        while(j<n){
            if(nums[i]==nums[j]){
                counter++;
                j++;
            }
            else if(nums[i]!=nums[j]){
                if(counter>n/2){
                    return nums[i];
                    break;
                }
                else{
                    counter=0;
                }
                i = j;
            }
        }
        if(counter>n/2){
            return nums[i];      
        }
    return -1;
    }
};