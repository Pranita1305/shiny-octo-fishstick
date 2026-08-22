class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;

        int t=n;

        while(t>0){
            sum+=t%10;
            prod*=t%10;
            t/=10;
        }

        return n%(sum+prod)==0;
    }
};