class Solution {
public:
    int totalMoney(int n) {
        int mon = 1;
        int ans = 0;
        while (n > 0) {
            for (int day = 0; day < min(n, 7); day++) {
                ans += mon + day;
            }
            n -= 7;
            mon++;
        }
        return ans;
    }
};