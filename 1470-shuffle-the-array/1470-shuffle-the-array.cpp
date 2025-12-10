class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        for (int j = 0; j < n; j++) {
            ans[2 * j] = nums[j];
            ans[2 * j + 1] = nums[j + n];
        }
        return ans;
    }
};