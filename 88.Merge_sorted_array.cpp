class Solution {
public:
  
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      //For loop to add all elements of num2 after the elements of num1
        for(int i = m ; i < m + n ; i++)
        {
            nums1[i] = nums2[i - m];
        }
        
		//Sorting updated num1 elements to get the desired result
        sort(nums1.begin() , nums1.end());
    }
};