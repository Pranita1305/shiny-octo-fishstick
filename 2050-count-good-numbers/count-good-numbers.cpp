class Solution {
    const long long MOD = 1e9 + 7;
public:
    int countGoodNumbers(long long n) {
        long long even_places = (n + 1) / 2;
        long long prime_places = n / 2;
        long long ans = (modPow(5, even_places) * modPow(4, prime_places)) % MOD;
        return static_cast<int>(ans);
    }
private:
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base = base % MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp = exp / 2;
        }
        return result;
    }
};