class Solution {
public:
    int minimumPushes(string word) {
        
        int n=word.size();

        int blocks=n/8;
        int rem=n%8;

        int pushes=0;
        int tap=1;
        for(int i=0;i<blocks;i++){
            pushes+=(8*tap);
            tap++;
        }

        pushes+=(rem*tap);

        return pushes;

    }
};