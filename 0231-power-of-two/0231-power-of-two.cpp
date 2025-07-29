// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         for(int i=0;i<31;i++){
//             int answer=pow(2,i);
//             if(answer==n) return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        while(n%2==0){
            n/=2;
        }
        return n==1;
    }
};