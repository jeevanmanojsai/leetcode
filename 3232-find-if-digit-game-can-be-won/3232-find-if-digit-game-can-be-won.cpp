class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single = 0, dbl = 0;

        for (int x : nums) {
            if (x <= 9) single += x;
            else dbl += x;
        }

        return (single > dbl) || (dbl > single);
    }
};
