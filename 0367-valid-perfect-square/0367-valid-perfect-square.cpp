class Solution {
public:
    bool isPerfectSquare(int num){
       int k=sqrt(num);
     if(k*k==num){
        return true;
     }
     return false;
    }

};