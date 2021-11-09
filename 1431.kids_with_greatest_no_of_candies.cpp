class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans;
    int maxi = 0, n = candies.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(candies[i], maxi);
    }
    for (int j = 0; j < n; j++)
    {
        if (candies[j] + extraCandies >= maxi)
            ans.push_back(1);
        else
            ans.push_back(0);
    }
    return ans;
    }
};
