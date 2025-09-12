// class Solution {
// public:
//     int totalMoney(int n) {
//         int mon = 1;
//         int ans = 0;
//         while (n > 0) {
//             for (int day = 0; day < min(n, 7); day++) {
//                 ans += mon + day;
//             }
//             n -= 7;
//             mon++;
//         }
//         return ans;
//     }
// };




class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, weekStart = 1;
        for (int day = 0; day < n; day++) {
            ans += weekStart + (day % 7);  
            if (day % 7 == 6) weekStart++; 
        }
        return ans;
    }
};
