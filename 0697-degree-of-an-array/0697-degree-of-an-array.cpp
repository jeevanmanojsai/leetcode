class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            count[x]++;
            if (!first.count(x)) {
                first[x] = i;
            }
            last[x] = i;
        }

        int degree = 0;
        for (auto &p : count) {
            degree = max(degree, p.second);
        }

        int ans = nums.size();
        for (auto &p : count) {
            if (p.second == degree) {
                ans = min(ans, last[p.first] - first[p.first] + 1);
            }
        }

        return ans;
    }
};
