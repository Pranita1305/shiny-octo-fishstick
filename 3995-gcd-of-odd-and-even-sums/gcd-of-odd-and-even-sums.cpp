class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sum_odd=sum_n(n,1);
        int sum_even=sum_n(n,2);

        return gcd(sum_even,sum_odd);
    }
private:
    int sum_n(int n, int start){
        if(n==0) return 0;
        return sum_n(n-1,start+2)+start;
    }
};