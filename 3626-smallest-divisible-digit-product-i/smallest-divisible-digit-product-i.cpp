class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        while(i>=n){
            if(prod(i)%t==0){
                break;
            }
            else{
                i++;
            }
        }
        return i;
    }
    int prod(int n){
        int p=1;
        while(n>0){
            p=p*(n%10);
            n=n/10;
        }
        return p;
    }
};