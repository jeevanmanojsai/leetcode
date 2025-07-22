int numWaterBottles(int numBottles, int numExchange) {
    int cnt=0;
    cnt+=numBottles;
    while(numBottles>=numExchange){
        int rem=numBottles % numExchange;
        int div =numBottles/ numExchange;
        numBottles = div + rem;
        cnt=cnt+div;
    }
    return cnt;
    
}