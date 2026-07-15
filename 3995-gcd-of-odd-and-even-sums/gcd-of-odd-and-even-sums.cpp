class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(sum_n(n,2),sum_n(n,1));
    }
private:
    int sum_n(int n, int start){
        if(n==0) return 0;
        return sum_n(n-1,start+2)+start;
    }
};