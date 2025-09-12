// class Solution {
// public:
//     bool canAliceWin(vector<int>& nums) {
//         int n = nums.size();
//         int add=0;int big=0;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] >= 1 && nums[i] <= 9) {
//                 add += nums[i];
//             } else {
//                  big+= nums[i];
//             }
//         }
//         return add>big;
//     }
// };

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
