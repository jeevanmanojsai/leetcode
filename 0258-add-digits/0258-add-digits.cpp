class Solution {
public:
    int addDigits(int num) {
        int sum =0;
      //  if(num<=0) return false;
        while(num){
            sum+=(num%10);
            num/=10;
        }
        if(sum<10){
            return sum ;
        }else{
            return addDigits(sum);
        }

    }
};