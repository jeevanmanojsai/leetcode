class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a=abs(z-x);
        int b=abs(z-y);
        if(a<b){
            return 1; //first person
        }else if(a>b){
            return 2; //second person
        }else{
            return 0; //both
        }
    }
};