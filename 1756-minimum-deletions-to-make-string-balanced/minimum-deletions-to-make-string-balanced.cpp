class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();

        int numA=0;

        for(int i=0;i<n;i++){
            if(s[i]=='a') numA++;
        }

        int leftB=0;
        int minDel=numA;

        for(int i=0;i<n;i++){
            if(s[i]=='b') leftB++;
            if(s[i]=='a') numA--;

            minDel=min(minDel,leftB+numA);
        }

        return minDel;
    }
};