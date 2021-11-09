//Easy to understand leetcode solution of 1470. Shuffle the array in C++

class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> res(2*n,0);

		for (int i = 0; i < n; ++i) {
			res[2*i] = nums[i];
			res[2*i+1] = nums[n+i];
		}

		return res;
	}
};