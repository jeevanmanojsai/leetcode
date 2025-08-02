class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;

        int total=0;
        int end=0;
        int n=timeSeries.size();
        for(int i=0;i<n;i++){
            if(timeSeries[i]>end){
                total +=duration;
            }else{
                total+=timeSeries[i]+duration - end;
            }
            end=timeSeries[i]+duration;
        }
        return total;
    }
};