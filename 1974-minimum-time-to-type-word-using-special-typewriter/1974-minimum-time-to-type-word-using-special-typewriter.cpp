class Solution {
public:
    int minTimeToType(string word) {
        int answer=0;
        int pointer='a';
        for(int i=0;i<word.length();i++){
            int clockwise =abs(word[i]-pointer);
            int anticlockwise =26-clockwise ;
            answer += min(clockwise ,anticlockwise)+1;
            pointer =word [i];
        }
        return answer;
    }
};