class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);

        for(int i=0;i<=n;i++){
            ans[i]=ans[i>>1] +(i&1);
        }
        return ans;
    }
};