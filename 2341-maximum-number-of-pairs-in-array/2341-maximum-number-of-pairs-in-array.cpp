class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());//sorting
        
        int pairs = 0;
        int leftover = 0;
        
        for (int i = 0; i < nums.size(); ) {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                pairs++;
                i += 2; // remove the pair
            } else {
                leftover++;
                i++; // leftover number
            }
        }
        
        return {pairs, leftover};
    }
};
