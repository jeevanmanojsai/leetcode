class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int k=*max_element(candies.begin(), candies.end());
        int  n=candies.size();
        vector<bool>result(n);
        for(int i=0;i<n;i++){
           result[i]=(candies[i]+extraCandies >=k);
        }
        return result;
    }
};