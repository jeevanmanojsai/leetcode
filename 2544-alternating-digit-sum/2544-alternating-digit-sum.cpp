class Solution {
public:
    int alternateDigitSum(int n) {
        int sum=0;
        while(n){
            sum =(n%10)-sum;
            n/=10;
        }
        return sum;
    }
};